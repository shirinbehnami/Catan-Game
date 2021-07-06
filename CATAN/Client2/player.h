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
    QString send(QString s);
};

#endif // PLAYER_H

