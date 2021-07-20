#ifndef CHART_H
#define CHART_H

#include<QLabel>
#include <ground/ground.h>
class chart: public QObject
{
public:
    chart();
    void update_chart(int index,int change);
    void set(ground* g);
    void set_color(int pl_num);
    void turn_on(int pl_num);
    void turn_off(int pl_num);
private:
    QLabel* score_titel;
    QLabel* name_titel;
    QLabel* names[3];
    QLabel* scores[3];

    int score[3];
    int houses_built[3];//not used yet

    QString colors[4]={"yellow","red","blue","green"};

    void set_position();


};

#endif // CHART_H
