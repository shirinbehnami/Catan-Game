#include "chart.h"

chart::chart()
{

}
void chart::set(ground* g)
{
    score_titel=new QLabel(g);
    score_titel->setText("Score");
    score_titel->setStyleSheet("background-color:rgb(20, 20, 140);font:bold;font-size:15px;color:white;");
    score_titel->setAlignment(Qt::AlignCenter);
    name_titel=new QLabel(g);
    name_titel->setText("Name");
    name_titel->setStyleSheet("background-color:rgb(20, 20, 140);font:bold;font-size:15px;color:white;");
    for(int i=0;i<3;i++)
    {
        names[i]=new QLabel(g);
        names[i]->setStyleSheet("background-color:rgb(181,144,246);");
        names[i]->setText("player"+QString::number(i+1));

        scores[i]=new QLabel(g);
        scores[i]->setStyleSheet("background-color:rgb(181,144,246);");
        scores[i]->setText("0");
        scores[i]->setAlignment(Qt::AlignCenter);

        score[i]=0;
    }
    set_position();
}
void chart::set_position()
{
    score_titel->setGeometry(1200,100,60,30);
    name_titel->setGeometry(1100,100,90,30);
    for(int i=0;i<3;i++)
    {
        scores[i]->setGeometry(1200,100+(i+1)*31,60,30);
        names[i]->setGeometry(1100,100+(i+1)*31,90,30);
    }
}
void chart::update_chart(int index,int change)
{
    //index means playernum
    score[index-1]+=change;
    scores[index-1]->setText(QString::number(score[index-1]));

}
void chart::turn_on(int pl_num)
{
    //qDebug()<<"turn on.";
    names[pl_num-1]->setStyleSheet("background-color:"+colors[pl_num-1]+";");
    scores[pl_num-1]->setStyleSheet("background-color:"+colors[pl_num-1]+";");
}
void chart::turn_off(int pl_num)
{
    names[pl_num-1]->setStyleSheet("background-color:rgb(181,144,246);");
    scores[pl_num-1]->setStyleSheet("background-color:rgb(181,144,246);");
}
