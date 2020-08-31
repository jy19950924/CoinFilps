#include "startscene.h"
#include<QPainter>
#include<levelselectscene.h>
#include<QTimer>
#include<QSound>
StartScene::StartScene(QWidget *parent) : myMainWindow(parent)
{
    MyPushBotton *btnStart=new MyPushBotton(":/MenuSceneStartButton.png","",this);

    btnStart->setFixedSize(QSize(114,114));
    btnStart->move((this->width()-btnStart->width())/2,
                   (this->height()-btnStart->height())*2/3);

    connect(btnStart,&MyPushBotton::clicked,[=](){

        btnStart->setEnabled(false);

        btnStart->moveDown();
        QSound::play(":/TapButtonSound.wav");
        QTimer::singleShot(100,[=](){
            btnStart->moveUp();
        });
        QTimer::singleShot(100,[=](){
            btnStart->setEnabled(true);
            LevelSelectScene* levelSelectScene=
                    new LevelSelectScene;
            levelSelectScene->setAttribute(Qt::WA_DeleteOnClose);
            levelSelectScene->move(this->pos());
            levelSelectScene->show();
            this->hide();

            connect(levelSelectScene,&LevelSelectScene::backBtnClicked,[=](){
                QSound::play(":/BackButtonSound.wav");
                this->show();
                levelSelectScene->close();
            });
        });

    });


}

void StartScene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    QPixmap pix(":/MenuSceneBg.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    myMainWindow::paintEvent(ev);

}
