#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H

#include <QWidget>
#include<QPushButton>
#include<QPixmap>
class MyPushBotton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushBotton(QWidget *parent = 0);
    MyPushBotton(QString normalImgPath,QString pressImgPath=" ",QWidget *parent = 0);

    QString mNormalImgPath;
    QString mPressedImgPath;
    void moveDown();
    void moveUp();
protected:
    void paintEvent(QPaintEvent * ev);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBOTTON_H
