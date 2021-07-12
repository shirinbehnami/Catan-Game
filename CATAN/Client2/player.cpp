#include "player.h"
#include <QApplication>

Player::Player(QObject *parent) : QObject(parent)
{
    this->connect();
}
void Player::connect(){
    socket=new QTcpSocket(this);
    socket->connectToHost("127.0.0.1",8080);
    if(socket->waitForConnected(3000)){
        qDebug()<<"connect!";
    }
    else
    {
        qDebug()<<"not connect!";
        QApplication::quit();
    }
}

void Player::send(QString s)
{
    QByteArray text;
    text=s.toUtf8();
    text+='\n';
    socket->write(text);
    socket->waitForBytesWritten(1000);
}

QString Player::recieve()
{
    QByteArray* text=new QByteArray();
    socket->waitForReadyRead(60000);
    *text =socket->readAll();
    qDebug()<<*text;
    return QString::fromUtf8(*text);

    /*QByteArray text;
    text.reserve(socket->bytesAvailable());
    text = socket->readAll();
    qDebug()<<text;
    return QString::fromUtf8(text);*/
}
