#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setReadOnly(true);
    P=new Player();

    QMetaObject::Connection * const c = new QMetaObject::Connection;
    *c = connect(ui->Sendbtn, &QPushButton::pressed, [this,c](){
        QObject::disconnect(*c);
        delete c;
        connection();
    });

    //connect(ui->Sendbtn,SIGNAL(pressed()),this,SLOT(connection()));
}
void MainWindow::connection()
{
    QString input=ui->lineEdit->text();
    P->send(input);
    QString output = P->recieve();
    qDebug()<<output;
    P->Cnumber=output.toInt();
    QPalette *palette = new QPalette();

    if(output=="1")
        palette->setColor(QPalette::Base,Qt::red);
    else if(output=="2")
        palette->setColor(QPalette::Base,Qt::blue);
    else if(output=="3")
        palette->setColor(QPalette::Base,Qt::yellow);

    ui->lineEdit_2->setPalette(*palette);
    ui->lineEdit_2->setText("This is your color:))");

    if(output=="1")
        number_of_player();
    else
    {
        //send_nonesense();
        make_ground();
    }

}

void MainWindow::number_of_player()
{
    ui->label->setText("Specify the number of players (3 or 4)");
    ui->lineEdit->clear();

    //connect(ui->Sendbtn,SIGNAL(pressed()),this,SLOT(send_number_of_player()));

    QMetaObject::Connection * const c = new QMetaObject::Connection;
    *c = connect(ui->Sendbtn, &QPushButton::pressed, [this,c](){
        QObject::disconnect(*c);
        delete c;
        send_number_of_player();
    });
}

void MainWindow::send_number_of_player()
{
    QString input=ui->lineEdit->text();
    if(input !="3" && input!="4")
    {
        QMessageBox::information(this, tr("error"),"The correct value is not entered in the box");
        number_of_player();
    }
    else
    {
        P->send(input);
        make_ground();
    }
}

void MainWindow::make_ground()
{
    QString output = P->recieve();

    G = new game(output.toUtf8().constData(),P);

    G->show();

    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

