#include <QApplication>
#include <QMessageBox>
#include "game.h"

game::game(string s,Player* _p,int _cn,QObject *parent): QObject(parent)
{
    g=new ground(_p->get_playernum(),s);
    ch=new class::chart();
    ch->set(g);
    p=_p;
    p->clean_obj_built_string();
    turn=0;
    client_num = _cn;
    set_house_maker();
    set_road_maker();


    connect(g,SIGNAL(ColorShapenode()),p,SLOT(addScore()));
    connect(g, &ground::turn_pressed, p,[&]() {p->set_my_turn(false);});
    connect(g, SIGNAL(obj_created(int)), p,SLOT(add_obj_to_msg(int)));
    connect(g,SIGNAL(roll_pressed(int)),p,SLOT(add_dice_to_msg(int)));
    connect(make_a_house,SIGNAL(clicked),this,SLOT(make_house()));
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
    {
        play();
    }
    else
    {
          if(p->get_playernum()==turn)
          {
               p->set_my_turn(true);
               ch->turn_on(p->get_playernum());
               g->enabel_nodes();
               qApp->processEvents();
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
             //?
             ch->update_chart(turn,1);
             ch->turn_off(turn);
             qApp->processEvents();
             opening(n);

         }


    }
}

void game::make_road(int n)
{
    g->disabel_nodes();
    int pos=(p->get_obj_built()).lastIndexOf(QChar('-'));
    g->enabel_roads(((p->get_obj_built()).left(pos)).toInt());
    //?
    qApp->processEvents();
    QMetaObject::Connection * const c = new QMetaObject::Connection;
    *c = connect(g, &ground::turn_pressed, [this,c,n](){
        QObject::disconnect(*c);
        delete c;
        opening_turn_finish(n);
    });
}

void game::opening_turn_finish(int n)
{
    p->send_obj();
    if(n==2)
    {
        g->Card_distribution(p);
        qApp->processEvents();
    }
    p->clean_obj_built_string();
    g->disabel_roads();
    //?
    ch->update_chart(turn,1);
    ch->turn_off(turn);
    qApp->processEvents();
    opening(n);
}

void game::play()
{
    turn++;

    if(turn>client_num)
        turn = 1;
    ch->turn_on(turn);
    if(p->get_playernum()==turn)
    {
        g->enabel_dice();
        QMetaObject::Connection * const c = new QMetaObject::Connection;
        *c = connect(g, &ground::roll_pressed, [this,c](){
            QObject::disconnect(*c);
            delete c;
            g->disabel_dice();
            p->send_dice();
            int sum = update_dice(p->get_dice());
            g->Card_distribution(p,sum);
            qApp->processEvents();
            play();
        });
    }
    else
    {
        QString msg=p->recieve();
        int sum=update_dice(msg);
        g->Card_distribution(p,sum);
        qApp->processEvents();
        play();
    }
}

int game::update_dice(QString s)
{
    int x=s.toInt();
    g->setdice(x/10,x%10);
    return x/10+x%10;
}
void game::set_house_maker()
{
    make_a_house=new QPushButton(g);
    make_a_house-> setGeometry(950,650,100,40);
    make_a_house->setText("make a house!");
    make_a_house->setStyleSheet("background-color:rgb(181,144,300);");
}
void game::set_road_maker()
{
    make_a_road=new QPushButton(g);
    make_a_road-> setGeometry(950,700,100,40);
    make_a_road->setText("make a rode!");
    make_a_road->setStyleSheet("background-color:rgb(181,144,300);");
}
void game::make_house()
{
    if(p->check_budget("house"))
        g->enabel_nodes();
   // else
       //QMessageBox::information(this, tr("error"),"your budget is not enugh.");
}
