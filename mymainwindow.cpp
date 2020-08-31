#include "mymainwindow.h"
#include "ui_mymainwindow.h"


myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);

    setFixedSize(320,588);
    setWindowTitle("CoinFilps");
    setWindowIcon(QIcon(":/Coin0001.png"));
}

myMainWindow::~myMainWindow()
{
    delete ui;
}
