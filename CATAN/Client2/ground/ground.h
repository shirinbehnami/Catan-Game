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
#include <ground/road.h>
#include <ground/robber.h>
#include <card/sourcecard.h>
#include <player.h>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class ground; }
QT_END_NAMESPACE

#define hex_num 28
#define water_num 42
#define nodes_num 95
#define road_num 119
#define bridge_num 36

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

    void enabel_roads();
    void enabel_roads(int node_index);
    void disabel_roads();
    void update_roads(int k,int pl_num);

    void enabel_dice();
    void disabel_dice();

    void Invisible_all();
    void visible_all();

    void set_city_colors();
    bool check_node(node* n,int pl_num);
    bool check_node_in_game(node* n,int pl_num);

    void Card_distribution(Player* p);
    void Card_distribution(Player* p,int sum);

    void changeRobberLocation(int x);

signals:
    void ColorShapenode();
    void ColorShaperoad();
    void turn_pressed();
    void obj_created(int index);
    void roll_pressed(int n);
    void robber_change();

private:
    Ui::ground *ui;
    QString* city_colors[4];
    QLabel* labels[hex_num];
    hexagonal* m_hexagonal[hex_num];
    hexagonal* m_water[water_num];
    node* m_nodes[nodes_num];
    roads* m_roads[road_num];
    roads* m_bridges[bridge_num];
    robber* Robber[hex_num];

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
    map<int, vector<int>> roadmap =  {
    {0,{0,40}},
    {1,{40,41}},
    {2,{41,42}},
    {3,{42,43}},
    {4,{2,43}},
    {5,{3,44}},
    {6,{44,45}},
    {7,{4,45}},
    {8,{0,46}},
    {9,{46,47}},
    {10,{47,48}},
    {11,{48,49}},
    {12,{2,49}},
    {13,{3,50}},
    {14,{5,50,51}},
    {15,{4,51,52}},
    {16,{6,52,53}},
    {17,{53,54}},
    {18,{7,54}},
    {19,{8,55}},
    {20,{55,56}},
    {21,{9,56,57}},
    {22,{57,58}},
    {23,{10,58,59}},
    {24,{59,60}},
    {25,{11,60}},
    {26,{5,61}},
    {27,{12,61,62}},
    {28,{6,62,63}},
    {29,{13,63,64}},
    {30,{7,64}},
    {31,{14,65}},
    {32,{8,65,66}},
    {33,{15,66,67}},
    {34,{9,67,68}},
    {35,{16,68,69}},
    {36,{10,69,70}},
    {37,{17,70,71}},
    {38,{11,71,72}},
    {39,{18,72}},
    {40,{12,73}},
    {41,{19,73,74}},
    {42,{13,74,75}},
    {43,{20,75}},
    {44,{21,76}},
    {45,{14,76,77}},
    {46,{22,77,78}},
    {47,{15,78,79}},
    {48,{23,79,80}},
    {49,{16,80,81}},
    {50,{24,81,82}},
    {51,{17,82,83}},
    {52,{25,83,84}},
    {53,{18,84,85}},
    {54,{26,85}},
    {55,{19,86}},
    {56,{86,87}},
    {57,{20,87}},
    {58,{21,88}},
    {59,{27,88,89}},
    {60,{22,89,90}},
    {61,{28,90,91}},
    {62,{23,91,92}},
    {63,{29,92,93}},
    {64,{24,93,94}},
    {65,{30,94,95}},
    {66,{25,95,96}},
    {67,{31,96,97}},
    {68,{26,97}},
    {69,{32,98}},
    {70,{98,99}},
    {71,{33,99}},
    {72,{27,100}},
    {73,{34,100,101}},
    {74,{28,101,102}},
    {75,{35,102,103}},
    {76,{29,103,104}},
    {77,{36,104,105}},
    {78,{30,105,106}},
    {79,{37,106,107}},
    {80,{31,107}},
    {81,{38,108}},
    {82,{32,108,109}},
    {83,{39,109,110}},
    {84,{33,110}},
    {85,{34,111}},
    {86,{111,112}},
    {87,{35,112,113}},
    {88,{113,114}},
    {89,{36,114,115}},
    {90,{115,116}},
    {91,{37,116}},
    {92,{38,117}},
    {93,{117,118}},
    {94,{39,118}},
    };
    map<int, vector<int>> node_neighberhood;

    void set_hexagonal();
    void set_node(int pl_num);
    void set_road(int pl_num);
    void set_bridge();
    void set_robber(int desert_num);

public slots:
    void roll();
    void ChangeShapenode(int pl_num);
    void ChangeShaperoad(int pl_num);
    void next_turn_pressed();
    void changeRobberLocation(robber* RB);

};
#endif // GROUND_H
