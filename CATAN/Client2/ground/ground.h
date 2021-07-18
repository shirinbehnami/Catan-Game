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
#include <card/sourcecard.h>
#include <player.h>


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
    void setdice(int a,int b);
    void setwidgets();

    void create_node_neighberhood();

    void enabel_nodes();
    void disabel_nodes();
    void update_node(int k,int pl_num);
    void set_city_colors();
    bool check_node(node* n,int pl_num);

    void Card_distribution(int roll_num);
    void Card_distribution(Player* p);

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

    map<int, vector<int>> hex_neighberhood = {
                {0,{19,20,21,34,33,32}},
                {1,{21,22,23,36,35,34}},
                {2,{23,24,25,38,37,36}},
                {3,{31,32,33,47,46,45}},
                {4,{33,34,35,49,48,47}},
                {5,{35,36,37,51,50,49}},
                {6,{37,38,39,53,52,51}},
                {7,{44,45,46,60,59,58}},
                {8,{46,47,48,62,61,60}},
                {9,{48,49,50,64,63,62}},
                {10,{50,51,52,66,65,64}},
                {11,{52,53,54,68,67,66}},
                {12,{59,60,61,74,73,72}},
                {13,{61,62,63,76,75,74}},
                {14,{63,64,65,78,77,76}},
                {15,{65,66,67,80,79,78}},
                {16,{73,74,75,87,86,85}},
                {17,{75,76,77,89,88,87}},
                {18,{77,78,79,91,90,89}},
                {19,{0,1,2,10,9,8}},
                {20,{2,3,4,12,11,10}},
                {21,{5,6,7,15,14,13}},
                {22,{14,15,16,28,27,26}},
                {23,{16,17,18,30,29,28}},
                {24,{27,28,29,42,41,40}},
                {25,{41,42,43,57,56,55}},
                {26,{69,70,71,84,83,82}},
                {27,{81,82,83,94,93,92}},
        };
    //--------------------------------------------------
    map<int, vector<int>> node_neighberhood;
public slots:
    void roll();
    void ChangeShape(int pl_num);
    void next_turn_pressed();

};
#endif // GROUND_H
