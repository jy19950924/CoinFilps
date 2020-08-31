#include "coinbutton.h"
#include<QPushButton>
#include<QPainter>
#include<QTimer>
#include<QIcon>
#include<QWindow>
CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    setStyleSheet("QPushButton{border:None;}");

    mTimer=new QTimer(this);
    connect(mTimer,&QTimer::timeout,[=](){
        if(mStat){

            --mFrameNo;
        }else{
            ++mFrameNo;
        }
        if(mFrameNo==1||mFrameNo==8)
            mTimer->stop();
        QString iconName=QString(":/Coin000%1.png").arg(mFrameNo);
        setIcon(QIcon(iconName));
    });
}

void CoinButton::flip()
{
    //this->setStat(!this->stat());
    this->setStatWithAnimation(!this->stat());
}

void CoinButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix(":/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPushButton::paintEvent(e);
}

void CoinButton::setStatWithAnimation(int stat)
{
    mStat=stat;
    if(mStat){
        this->mFrameNo=8;
    }else{
        this->mFrameNo=1;
    }

    this->mTimer->start(30);
}

int CoinButton::stat() const
{
    return this->mStat;
}

void CoinButton::setStat(int stat)
{
    mStat=stat;
    if(mStat){
        this->setIcon(QIcon(":/Coin0001.png"));
    }else{
        this->setIcon(QIcon(":/Coin0008.png"));
    }
    this->setIconSize(this->size());
}
