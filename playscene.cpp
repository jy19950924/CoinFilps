#include "playscene.h"
#include<QMenuBar>
#include<QPainter>
#include<QLabel>
#include<QFont>
#include<QTimer>
#include<QPropertyAnimation>
#include<QMessageBox>
#include<QSound>
PlayScene::PlayScene(int level,QWidget *parent) : myMainWindow(parent),mLevel(level)
{
    MyPushBotton* closeBtn=new MyPushBotton(":/BackButton.png",
                                            ":/BackButtonSelected.png",
                                            this);
    closeBtn->move(this->width()-closeBtn->width(),
                   this->height()-closeBtn->height());
    connect(closeBtn,&MyPushBotton::clicked,[=](){
       emit this->backBtnClicked();
    });

    dataConfig config;
    QVector<QVector<int>> levelData=config.mData[mLevel];

    //
    const int rowCount =4;
    const int columnCount=4;

    const int rowHeight=50;
    const int columnWidth=50;

    const int xOffset=57;
    const int yOffset=200;

    const int coinWidth=50;
    const int coinHeight=50;
    for(int row=0;row<rowCount;++row){
        for(int column=0;column<columnCount;++column){
            int x=column*columnWidth+xOffset;
            int y=row*rowHeight+yOffset;
            CoinButton *btn=new CoinButton(this);

            mCoinBtns[row][column]=btn;

            btn->setGeometry(x,y,coinWidth,coinHeight);
            //btn->setStat(1);
            btn->setStat(levelData[row][column]);

            connect(btn,&CoinButton::clicked,[=](){
                QSound::play(":/ConFlipSound.wav");
                flipCoin(row,column);
            });
        }
    }

}

void PlayScene::flipCoin(int row, int column)
{
    if(mHasWin)return;
    this->mCoinBtns[row][column]->flip();
    QTimer::singleShot(100,[=](){
        if(row-1>=0){
            this->mCoinBtns[row-1][column]->flip();
        }
        if(row+1<4){
            this->mCoinBtns[row+1][column]->flip();
        }
        if(column-1>=0){
            this->mCoinBtns[row][column-1]->flip();
        }
        if(column+1<4){
            this->mCoinBtns[row][column+1]->flip();
        }
        //每次翻硬币后判断是否胜利
        QTimer::singleShot(100,[=](){
            this->judgeWin();
        });

    });


}

void PlayScene::judgeWin()
{
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            if(mCoinBtns[row][col]->stat()==0){
                return;
            }
        }
    }
    mHasWin=true;
    //QMessageBox::information(this,"good","Win!");
    QLabel* winLabel =new QLabel(this);
    QPixmap tmPix;
    tmPix.load(":/LevelCompletedDialogBg.png");
    winLabel->resize(tmPix.width(),tmPix.height());
    winLabel->setPixmap(tmPix);
    winLabel->move((this->width()-tmPix.width())*0.5,
                   tmPix.height());
    winLabel->show();

    QPropertyAnimation* animation=new  QPropertyAnimation(winLabel,"geometry");
    QSound::play(":/LevelWinSound.wav");
    animation->setDuration(1000);
    animation->setStartValue(winLabel->geometry());//开始值为label的位置（geometry）
    animation->setEndValue(QRect(winLabel->x(),
                                 winLabel->y()+10,
                                 winLabel->width(),
                                 winLabel->height()));
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void PlayScene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.translate(0,this->menuBar()->height());
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //logo
    pix.load(":/Title.png");
    painter.drawPixmap((this->width()-pix.width())/2,30,pix.width()*0.5,pix.height()*0.5,pix);

    QLabel *label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str=QString("Level %1").arg(this->mLevel);
    label->setText(str);
    label->setGeometry(QRect(30,this->height()-50,150,50));



}
