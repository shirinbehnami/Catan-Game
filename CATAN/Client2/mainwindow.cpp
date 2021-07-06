#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setReadOnly(true);
    P=new Player();
    connect(ui->Sendbtn,SIGNAL(released()),this,SLOT(connection()));
}
void MainWindow::connection()
{
    QString input=ui->lineEdit->text();
    QString output;
    output=P->send(input);
    QPalette *palette = new QPalette();
    if(output=="1\n")
         palette->setColor(QPalette::Base,Qt::red);
    else if(output=="2\n")
         palette->setColor(QPalette::Base,Qt::blue);
    else if(output=="3\n")
         palette->setColor(QPalette::Base,Qt::yellow);

    ui->lineEdit_2->setPalette(*palette);
    ui->lineEdit_2->setText("This is your color:))");


}
MainWindow::~MainWindow()
{
    delete ui;
}

