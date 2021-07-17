#include <QApplication>

#include "game.h"

game::game(string s,Player* _p,int _cn,QObject *parent): QObject(parent)
{
    g=new ground(_p->get_playernum(),s);
    p=_p;
    p->clean_houses_built_string();
    turn=0;
    client_num = _cn;

    connect(g,SIGNAL(ColorShape()),p,SLOT(addScore()));
    connect(g, &ground::turn_pressed, p,[&]() {p->set_my_turn(false);});
    connect(g, SIGNAL(house_created(int)), p,SLOT(add_house_to_msg(int)));
}

void game::show()
{
    g->showMaximized();
}
void game::opening(int n)
{
    qDebug()<<"opening1";

    if(n==1)
        turn++;
    else
        turn--;

    if(turn>client_num)
        opening(2);
    else if(turn<1)
        return;
        //play
    else
    {
          if(p->get_playernum()==turn)
          {
               g->enabel_nodes();
               p->set_my_turn(true);
               connect(g, &ground::turn_pressed, this,[=]() {turn_finish(n);});
          }
         else
         {
             QString index=p->recieve();
             g->update_node(index.toInt(),turn);
             qApp->processEvents();
             opening(n);
         }

    }
}

void game::turn_finish(int n)
{
     p->send_houses();
    p->clean_houses_built_string();
    g->disabel_nodes();
    opening(n);
}
