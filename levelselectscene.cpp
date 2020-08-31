#include "levelselectscene.h"
#include<QPainter>
#include<QSound>
LevelSelectScene::LevelSelectScene(QWidget *parent) : myMainWindow(parent)
{
    this->setWindowTitle("CoinFilps-SelectLevel");

    MyPushBotton* closeBtn=new MyPushBotton(":/BackButton.png",
                                            ":/BackButtonSelected.png",this);
    closeBtn->setFixedSize(72,32);
    closeBtn->move(this->width()-closeBtn->width(),
                   this->height()-closeBtn->height());
    connect(closeBtn,&MyPushBotton::clicked,[=](){
        emit this->backBtnClicked();
    });
    const int columnWidth=70;
    const int rowHight=70;
    const int xOffset=25;
    const int yOffset=this->height()-25-5*rowHight;


    for(int i=0;i<20;i++){
        int row=i/4;
        int colum=i%4;
        int x=xOffset+columnWidth*colum;
        int y=yOffset+row*rowHight;
        MyPushBotton* btn=
                new MyPushBotton(":/LevelIcon.png","",this);
        btn->setText(QString::number(i+1));
        btn->setGeometry(x,y,57,57);


        connect(btn,&MyPushBotton::clicked,[=](){
            this->hide();
            QSound::play(":/TapButtonSound.wav");
            PlayScene* ps=new PlayScene(i+1);

            ps->setAttribute(Qt::WA_DeleteOnClose);
            ps->move(this->pos());
            ps->show();
            //监听
            connect(ps,&PlayScene::backBtnClicked,[=](){
               QSound::play(":/BackButtonSound.wav");
               this->show();
                ps->close();
            });
        });


    }

}

void LevelSelectScene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //logo
    pix.load(":/Title.png");
    painter.drawPixmap((this->width()-pix.width())/2,30,
                       pix.width(),pix.height(),pix);

    //myMainWindow::paintEvent(ev);

}
