#ifndef STARTSCENE_H
#define STARTSCENE_H
#include"mymainwindow.h"
#include <QMainWindow>
#include"mypushbotton.h"
class StartScene : public myMainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent * ev);


signals:

public slots:
};

#endif // STARTSCENE_H
