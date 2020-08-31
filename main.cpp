#include "mymainwindow.h"
#include <QApplication>
#include<startscene.h>
#include<levelselectscene.h>
#include<playscene.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //myMainWindow w;
    //w.show();

    StartScene sc;
    sc.show();
//    LevelSelectScene lc;
//    lc.show();
//   PlayScene pc(1);
//   pc.show();
    return a.exec();
}
