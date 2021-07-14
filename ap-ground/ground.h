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
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class ground; }
QT_END_NAMESPACE

#define hex_num 28
#define water_num 42
#define nodes_num 112
class hexagonal;
class node;
class cards;
class ground : public QMainWindow
{
    Q_OBJECT

public:
    ground(QWidget *parent = nullptr);
    ~ground();

    int makeground();
    void setnumbers(vector<int>final);
    void setnumbers(int desert_index);
    void setdice(int a,int b);
    void setwidgets();

private:
    Ui::ground *ui;
    QLabel* labels[hex_num];
    hexagonal* m_hexagonal[hex_num];
    node* m_nodes[nodes_num];
    hexagonal* m_water[42];
<<<<<<< HEAD

    vector<cards*> cr;
=======
    QLabel* dice[2];
    QPushButton* rollbtn;
    QPushButton* nextturn;
public slots:
    void roll();
>>>>>>> 9f938246a3f9f4305bfe59badc7243ffe9ddd77c
};
#endif // GROUND_H
