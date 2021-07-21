#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QMainWindow>
#include <algorithm>
#include <iostream>
#include <card/card.h>
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
    QString get_string_color();
    QString get_dice(){return dice;}

    void connect();

    void send(QString s);
    QString recieve();
    QString create_msg();

    void Addcard(cards* c);

    void clean_obj_built_string(){obj_built="";}
    QString get_obj_built(){return obj_built;}
    void send_obj(){send(obj_built);}
    void send_dice(){send(dice);}

    bool check_budget(QString structure);
    void pay();

private:
    QTcpSocket* socket;

    int myplayernum;
    int score;
    bool my_turn;
    QString obj_built;
    QColor mycolor;
    QString dice;
    QMap<QString,QVector<cards*>> mycard;
    std::map<QString,std::vector<QString>> costs={
        {"house",{"sheep","wood","wheat","clay"}},
        {"road",{"wood","clay"}},
       // {"city",{}},
       // {"bridge",{}},
    //to be continiued...
    };

    void updatecards();

public slots:
    void set_my_turn(bool mt){my_turn=mt;}
    void add_obj_to_msg(int index){obj_built+=(QString::number(index)+'-');}
    void add_dice_to_msg(int s){dice=QString::number(s);}

private slots:
    void addScore(){score++;}
};


#endif // PLAYER_H

