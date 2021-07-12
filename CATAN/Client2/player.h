#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
class Player: public QObject
{
  Q_OBJECT
public:
    QTcpSocket* socket;
    explicit Player(QObject *parent = nullptr);
    void connect();

    void send(QString s);
    QString recieve();


};


#endif // PLAYER_H

