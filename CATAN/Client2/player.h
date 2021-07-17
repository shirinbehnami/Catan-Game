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
    virtual ~Player(){};
    void set_playernum(int n);
    int get_playernum(){return myplayernum;}
    bool is_my_turn(){return my_turn;}
    QColor get_color(){return mycolor;}

    void connect();

    void send(QString s);
    QString recieve();
    QString create_msg();

    void Addcard(cards* c);

    void clean_houses_built_string(){houses_built="";}
    void send_houses(){send(houses_built);}

private:
    QTcpSocket* socket;
    int myplayernum;
    int score;
    bool my_turn;
    QString houses_built;
    QColor mycolor;
    QMap<QString,QVector<cards*>> mycard;

    void updatecards();

public slots:
    void set_my_turn(bool mt){my_turn=mt;}
    void add_house_to_msg(int index){houses_built+=QString::number(index);}

private slots:
    void addScore(){score++;}
};


#endif // PLAYER_H

