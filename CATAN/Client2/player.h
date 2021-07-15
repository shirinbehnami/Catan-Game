#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QMainWindow>

class cards;

class Player: public QObject
{
  Q_OBJECT
public:

    explicit Player(QObject *parent = nullptr);

    void set_playernum(int n);
    int get_playernum(){return myplayernum;}

    QColor get_color(){return mycolor;}

    void connect();

    void send(QString s);
    QString recieve();

    void Addcard(cards* c);

private:
    QTcpSocket* socket;
    int myplayernum;

    QColor mycolor;

    QMap<QString,QVector<cards*>> mycard;

    void updatecards();
};


#endif // PLAYER_H

