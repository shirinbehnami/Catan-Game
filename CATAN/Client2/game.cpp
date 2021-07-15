#include "game.h"

game::game(string s,Player* _p)
{
    g=new ground(s);
    p=_p;
}

void game::show()
{
    g->showMaximized();
}
void game::opening()
{
    if(p->get_playernum()==1)
      { p->recieve();
        qDebug()<<"opening starts here.";
       g->enabel_nodes();
       p->send("4");
      }
    else
    {
        QString index=p->recieve();
        g->update_node(index.toInt());
    }



}
