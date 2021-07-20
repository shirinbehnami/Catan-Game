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

    void set_city_colors();
    bool check_node(node* n,int pl_num);
    bool check_node_in_game(node* n,int pl_num);

    void Card_distribution(Player* p);
    void Card_distribution(Player* p,int sum);

signals:
    void ColorShapenode();
    void ColorShaperoad();
    void turn_pressed();
    void obj_created(int index);
    void roll_pressed(int n);


private:
    Ui::ground *ui;
    QString* city_colors[4];
    QLabel* labels[hex_num];
    hexagonal* m_hexagonal[hex_num];
    hexagonal* m_water[water_num];
    node* m_nodes[nodes_num];
    roads* m_roads[road_num];
    roads* m_bridges[bridge_num];

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
  map<int, vector<roads*>> roadmap =  {
    {0,{m_roads[0],m_roads[40]}},
    {1,{m_roads[40],m_roads[41]}},
    {2,{m_roads[41],m_roads[42]}},
    {3,{m_roads[42],m_roads[43]}},
    {4,{m_roads[2],m_roads[43]}},
    {5,{m_roads[3],m_roads[44]}},
    {6,{m_roads[44],m_roads[45]}},
    {7,{m_roads[4],m_roads[45]}},
    {8,{m_roads[0],m_roads[46]}},
    {9,{m_roads[46],m_roads[47]}},
    {10,{m_roads[47],m_roads[48]}},
    {11,{m_roads[48],m_roads[49]}},
    {12,{m_roads[2],m_roads[49]}},
    {13,{m_roads[3],m_roads[50]}},
    {14,{m_roads[5],m_roads[50],m_roads[51]}},
    {15,{m_roads[4],m_roads[51],m_roads[52]}},
    {16,{m_roads[6],m_roads[52],m_roads[53]}},
    {17,{m_roads[53],m_roads[54]}},
    {18,{m_roads[7],m_roads[54]}},
    {19,{m_roads[8],m_roads[55]}},
    {20,{m_roads[55],m_roads[56]}},
    {21,{m_roads[9],m_roads[56],m_roads[57]}},
    {22,{m_roads[57],m_roads[58]}},
    {23,{m_roads[10],m_roads[58],m_roads[59]}},
    {24,{m_roads[59],m_roads[60]}},
    {25,{m_roads[11],m_roads[60]}},
    {26,{m_roads[5],m_roads[61]}},
    {27,{m_roads[12],m_roads[61],m_roads[62]}},
    {28,{m_roads[6],m_roads[62],m_roads[63]}},
    {29,{m_roads[13],m_roads[63],m_roads[64]}},
    {30,{m_roads[7],m_roads[64]}},
    {31,{m_roads[14],m_roads[65]}},
    {32,{m_roads[8],m_roads[65],m_roads[66]}},
    {33,{m_roads[15],m_roads[66],m_roads[67]}},
    {34,{m_roads[9],m_roads[67],m_roads[68]}},
    {35,{m_roads[16],m_roads[68],m_roads[69]}},
    {36,{m_roads[10],m_roads[69],m_roads[70]}},
    {37,{m_roads[17],m_roads[70],m_roads[71]}},
    {38,{m_roads[11],m_roads[71],m_roads[72]}},
    {39,{m_roads[18],m_roads[72]}},
    {40,{m_roads[12],m_roads[73]}},
    {41,{m_roads[19],m_roads[73],m_roads[74]}},
    {42,{m_roads[13],m_roads[74],m_roads[75]}},
    {43,{m_roads[20],m_roads[75]}},
    {44,{m_roads[21],m_roads[76]}},
    {45,{m_roads[14],m_roads[76],m_roads[77]}},
    {46,{m_roads[22],m_roads[77],m_roads[78]}},
    {47,{m_roads[15],m_roads[78],m_roads[79]}},
    {48,{m_roads[23],m_roads[79],m_roads[80]}},
    {49,{m_roads[16],m_roads[80],m_roads[81]}},
    {50,{m_roads[24],m_roads[81],m_roads[82]}},
    {51,{m_roads[17],m_roads[82],m_roads[83]}},
    {52,{m_roads[25],m_roads[83],m_roads[84]}},
    {53,{m_roads[18],m_roads[84],m_roads[85]}},
    {54,{m_roads[26],m_roads[85]}},
    {55,{m_roads[19],m_roads[86]}},
    {56,{m_roads[86],m_roads[87]}},
    {57,{m_roads[20],m_roads[87]}},
    {58,{m_roads[21],m_roads[88]}},
    {59,{m_roads[27],m_roads[88],m_roads[89]}},
    {60,{m_roads[22],m_roads[89],m_roads[90]}},
    {61,{m_roads[28],m_roads[90],m_roads[91]}},
    {62,{m_roads[23],m_roads[91],m_roads[92]}},
    {63,{m_roads[29],m_roads[92],m_roads[93]}},
    {64,{m_roads[24],m_roads[93],m_roads[94]}},
    {65,{m_roads[30],m_roads[94],m_roads[95]}},
    {66,{m_roads[25],m_roads[95],m_roads[96]}},
    {67,{m_roads[31],m_roads[96],m_roads[97]}},
    {68,{m_roads[26],m_roads[97]}},
    {69,{m_roads[32],m_roads[98]}},
    {70,{m_roads[98],m_roads[99]}},
    {71,{m_roads[33],m_roads[99]}},
    {72,{m_roads[27],m_roads[100]}},
    {73,{m_roads[34],m_roads[100],m_roads[101]}},
    {74,{m_roads[28],m_roads[101],m_roads[102]}},
    {75,{m_roads[35],m_roads[102],m_roads[103]}},
    {76,{m_roads[29],m_roads[103],m_roads[104]}},
    {77,{m_roads[36],m_roads[104],m_roads[105]}},
    {78,{m_roads[30],m_roads[105],m_roads[106]}},
    {79,{m_roads[37],m_roads[106],m_roads[107]}},
    {80,{m_roads[31],m_roads[107]}},
    {81,{m_roads[38],m_roads[108]}},
    {82,{m_roads[32],m_roads[108],m_roads[109]}},
    {83,{m_roads[39],m_roads[109],m_roads[110]}},
    {84,{m_roads[33],m_roads[110]}},
    {85,{m_roads[34],m_roads[111]}},
    {86,{m_roads[111],m_roads[112]}},
    {87,{m_roads[35],m_roads[112],m_roads[113]}},
    {88,{m_roads[113],m_roads[114]}},
    {89,{m_roads[36],m_roads[114],m_roads[115]}},
    {90,{m_roads[115],m_roads[116]}},
    {91,{m_roads[37],m_roads[116]}},
    {92,{m_roads[38],m_roads[117]}},
    {93,{m_roads[117],m_roads[118]}},
    {94,{m_roads[39],m_roads[118]}},
    };
    map<int, vector<int>> node_neighberhood;

    void set_hexagonal();
    void set_node(int pl_num);
    void set_road(int pl_num);
    void set_bridge();

public slots:
    void roll();
    void ChangeShapenode(int pl_num);
    void ChangeShaperoad(int pl_num);
    void next_turn_pressed();

};
#endif // GROUND_H
