#ifndef GAME_H
#define GAME_H
#include <ground/ground.h>
#include <player.h>
#include <iostream>

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
