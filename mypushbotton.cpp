#include "mypushbotton.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QPainter>
#include<QPixmap>
#include<QIcon>

MyPushBotton::MyPushBotton(QWidget *parent) : QPushButton(parent)
{


}

MyPushBotton::MyPushBotton(QString normalImgPath, QString pressImgPath, QWidget *parent):
    QPushButton(parent),mNormalImgPath(normalImgPath), mPressedImgPath(pressImgPath)
{
    QPixmap pixmap;
    bool ret=pixmap.load(normalImgPath);
    if(!ret){
        qDebug()<<mNormalImgPath<<"：Not find";
    }
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pixmap);
}

void MyPushBotton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix=this->icon().pixmap(QSize(this->width(),this->height()));
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter|Qt::AlignVCenter,
                     this->text());
}

void MyPushBotton::mousePressEvent(QMouseEvent *e)
{
    if(!mPressedImgPath.isEmpty()){
        QPixmap pix;
        bool ret=pix.load(mPressedImgPath);
        if(!ret){
            qDebug() << mPressedImgPath << ":Load Fail";
            return;

        }
        this->setIcon(pix);

    }
    QPushButton::mousePressEvent(e);
}

void MyPushBotton::mouseReleaseEvent(QMouseEvent *e)
{
    if(mNormalImgPath.isEmpty()){
        QPixmap pix;
        bool ret=pix.load(mNormalImgPath);
        if(!ret){
            qDebug()<<mNormalImgPath<<":Load Fail";
        }
        this->setIcon(pix);
    }
    QPushButton::mouseReleaseEvent(e);
}

void MyPushBotton::moveDown()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),
                                 this->y()+5,
                                 this->width(),
                                 this->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void MyPushBotton::moveUp()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),
                                 this->y()-5,
                                 this->width(),
                                 this->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}
