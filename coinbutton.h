#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include<QPushButton>
class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = 0);
    void flip();
    int stat() const;
    void setStat(int stat);
protected:
    void paintEvent(QPaintEvent * e);
signals:
private:
    void setStatWithAnimation(int stat);
    int mFrameNo;
    QTimer* mTimer;
    int mStat;



public slots:
};

#endif // COINBUTTON_H
