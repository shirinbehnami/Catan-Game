#ifndef GAME_H
#define GAME_H
#include <ground/ground.h>
#include <card/sourcecard.h>
#include <player.h>
#include <iostream>
#include <chart.h>
class game:public QObject
{
Q_OBJECT
public:
    explicit game(string s,Player* _p,int _cn,QObject *parent = nullptr);
    virtual ~game(){}

    void show();

    void opening(int n);

    void play();
    int update_dice(QString s);
private:
    ground* g;
    Player* p;
    chart* ch;

    int turn;
    int client_num;


private slots:
    void opening_turn_finish(int n);
    void make_road(int n);
};

#endif // GAME_H
