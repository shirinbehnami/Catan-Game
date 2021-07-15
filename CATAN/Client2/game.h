#ifndef GAME_H
#define GAME_H
#include <ground.h>
#include <player.h>
#include <iostream>
class ground;
class game
{
private:
ground* g;
Player* p;
public:
    game(string s,Player* _p);
    void show();
    void opening();
};

#endif // GAME_H
