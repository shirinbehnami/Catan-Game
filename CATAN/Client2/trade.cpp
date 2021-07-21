#include "trade.h"

trade::trade(QObject *parent): QObject(parent)
{
  connect(players_trade,SIGNAL(clicked()),this,SLOT(show()));
}
void trade::set(ground *g)
{
     bank_trade=new QPushButton(g);
     bank_trade->setText("Trade With Bank");
     bank_trade->setStyleSheet("background-color:rgb(181,144,246);");
     bank_trade->setGeometry(1000,275,300,40);
     players_trade=new QPushButton(g);
     players_trade->setText("players");
     players_trade->setGeometry(1000,320,300,40);
     players_trade->setStyleSheet("background-color:rgb(181,144,246);");
}
void trade::show()
{

}
