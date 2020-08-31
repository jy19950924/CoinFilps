#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<mymainwindow.h>
#include<mypushbotton.h>
#include<coinbutton.h>
#include<dataconfig.h>
class PlayScene : public myMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int level,QWidget *parent = 0);
    void flipCoin(int row,int column);
    void judgeWin();


protected:
    void paintEvent(QPaintEvent *ev);
signals:
    void backBtnClicked();
public slots:
private:
    bool mHasWin=false;
    int mLevel;
    CoinButton* mCoinBtns[4][4];

};

#endif // PLAYSCENE_H
