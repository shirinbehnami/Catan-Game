#ifndef GAME_H
#define GAME_H
#include <ground/ground.h>
#include <card/sourcecard.h>
#include <player.h>
#include <iostream>

class game:public QObject
{
Q_OBJECT
public:
    explicit game(string s,Player* _p,int _cn,QObject *parent = nullptr);
    virtual ~game(){}

    void show();

    void opening(int n);

   // void play();
private:
    ground* g;
    Player* p;
    int turn;
    int client_num;


private slots:
    void turn_finish(int n);
};

#endif // GAME_H
