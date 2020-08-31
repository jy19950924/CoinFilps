#ifndef LEVELSELECTSCENE_H
#define LEVELSELECTSCENE_H
#include"mymainwindow.h"
#include <QMainWindow>
#include<mypushbotton.h>
#include<playscene.h>
class LevelSelectScene : public myMainWindow
{
    Q_OBJECT
public:
    explicit LevelSelectScene(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent * ev);
signals:
    void backBtnClicked();

public slots:
};

#endif // LEVELSELECTSCENE_H
