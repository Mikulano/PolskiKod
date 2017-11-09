#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(SporzadzicZdanie()));
}

void MainWindow::SporzadzicZdanie(){
    ui->textBrowser->clear();
    _gen.usunac();
    _gen.SpZdanie();
    ui->textBrowser->setText(_gen.zostacZdanie());

}

MainWindow::~MainWindow()
{
    delete ui;
}
