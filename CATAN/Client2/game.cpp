#include <QApplication>

#include "game.h"

game::game(string s,Player* _p,int _cn,QObject *parent): QObject(parent)
{
    g=new ground(_p->get_playernum(),s);
    p=_p;
    p->clean_obj_built_string();
    turn=0;
    client_num = _cn;

    connect(g,SIGNAL(ColorShapenode()),p,SLOT(addScore()));
    connect(g, &ground::turn_pressed, p,[&]() {p->set_my_turn(false);});
    connect(g, SIGNAL(obj_created(int)), p,SLOT(add_obj_to_msg(int)));
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
               p->set_my_turn(true);
               g->enabel_nodes();

               QMetaObject::Connection * const c = new QMetaObject::Connection;
               *c = connect(g, &ground::ColorShapenode, [this,c,n](){
                   QObject::disconnect(*c);
                   delete c;
                   make_road(n);
               });

          }
         else
         {
             string s=p->recieve().toStdString();
             int end= s.find('-');
             int n1,n2;
             sscanf(s.substr(0,end).c_str(), "%d", &n1);
             sscanf(s.substr(end+1,s.length()-1).c_str(), "%d", &n2);
             g->update_node(n1,turn);
             g->update_roads(n2,turn);
             qApp->processEvents();
             opening(n);
         }

    }
}

void game::make_road(int n)
{
    g->disabel_nodes();
    qApp->processEvents();
    g->enabel_roads();
    QMetaObject::Connection * const c = new QMetaObject::Connection;
    *c = connect(g, &ground::turn_pressed, [this,c,n](){
        QObject::disconnect(*c);
        delete c;
        turn_finish(n);
    });
}

void game::turn_finish(int n)
{
    p->send_obj();
    if(n==2)
    {
        g->Card_distribution(p);
        qApp->processEvents();
    }
    p->clean_obj_built_string();
    g->disabel_roads();
    opening(n);
}
