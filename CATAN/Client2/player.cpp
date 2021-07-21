#include "player.h"
#include "card/card.h"


#include <QApplication>

Player::Player(QObject *parent) : QObject(parent)
{   
    this->connect();

    mycard.insert("wheat",{});
    mycard.insert("clay",{});
    mycard.insert("ore",{});
    mycard.insert("wood",{});
    mycard.insert("sheep",{});
    mycard.insert("LargestArmy",{});
    mycard.insert("RoadBuilder",{});

}

QString Player::get_string_color()
{
    switch (myplayernum) {
    case 1:
        return "yellow";
    case 2:
        return "red";
    case 3:
        return "blue";
    default:
        return "green";
    }
}

void Player::set_playernum(int n)
{
    myplayernum=n;
    switch (n) {
    case 1:
        mycolor = Qt::yellow;
        break;
    case 2:
        mycolor = Qt::red;
        break;
    case 3:
        mycolor = Qt::blue;
        break;
    case 4:
        mycolor = Qt::green;
        break;

    }
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
    socket->waitForBytesWritten(30000);
    socket->write(text);
}
QString Player::recieve()
{
    QByteArray* text=new QByteArray();
    socket->waitForReadyRead(30000);
    *text =socket->readAll();
    qDebug()<<*text;
    return QString::fromUtf8(*text);
}

void Player::Addcard(cards* c)
{
    QString s = c->get_state();
    mycard[s].push_back(c);
    updatecards();
}

void Player::updatecards()
{
    int x =920;

    QString states[] = {"wheat","clay","ore","wood","sheep","largestarmy","roadbuilder"};

    for (QString& state : states)
    {
          if(mycard[state].size()>0)
          {
              x+=40;
              for(auto& card : mycard[state])
              {
                  card->setGeometry(x,365,12,12);
                  x+=30;
              }
          }
    }
}
bool Player::check_budget(QString structure)
{

    if(structure=="house")
    {
        QString s="0000";
        QVector<cards*>v=mycard["house"];
        for(auto &p: v )
        {
            if(p->get_state()=="sheep")
                s[0]='1';
            else if(p->get_state()=="wood")
                s[1]='1';
            else if(p->get_state()=="wheat")
                s[2]='1';
            else if(p->get_state()=="clay")
                s[3]='1';

            if(s=="1111")
                return true;

        }
        return false;
    }
    else if(structure=="road")
    {
        QString s="00";
        QVector<cards*>v=mycard["road"];
        for(auto &p: v )
        {
            if(p->get_state()=="wood")
                s[0]='1';
           else if(p->get_state()=="clay")
                s[1]='1';
            if(s=="11")
                return true;
        }
        return false;
    }
    //to be continiued...
}
void Player::pay()
{
   // if(s=="house")
    {

    }
}
