#ifndef GROUND_H
#define GROUND_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSignalMapper>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <QLabel>

//---------------------custom libraries----------------------
#include <ground/hexagonal.h>
#include <ground/node.h>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class ground; }
QT_END_NAMESPACE

#define hex_num 28
#define water_num 42
#define nodes_num 95


class ground : public QMainWindow
{
    Q_OBJECT

public:
    ground(int colorNum,string s,QWidget *parent = nullptr);
    ~ground();

    int setResources(string s);
    void setnumbers(string s,int desert_num);
    void enabel_nodes();
    void disabel_nodes();
    void update_node(int k,int pl_num);
    void setdice(int a,int b);
    void setwidgets();
    void set_city_colors();
signals:
    void ColorShape();
    void turn_pressed();
    void house_created(int index);


private:
    Ui::ground *ui;
    QString* city_colors[4];
    QLabel* labels[hex_num];
    hexagonal* m_hexagonal[hex_num];
    node* m_nodes[nodes_num];
    hexagonal* m_water[42];

    QLabel* dice[2];
    QPushButton* rollbtn;
    QPushButton* nextturn;
public slots:
    void roll();
    void ChangeShape(int pl_num);
    void next_turn_pressed();

};
#endif // GROUND_H
