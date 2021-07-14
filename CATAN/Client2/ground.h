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

class hexagonal;

class ground : public QMainWindow
{
    Q_OBJECT

public:
    ground(string s,QWidget *parent = nullptr);
    ~ground();

    int setResources(string s);
    void setnumbers(string s,int desert_num);

private:
    Ui::ground *ui;
    QLabel* labels[hex_num];
    hexagonal* m_hexagonal[hex_num];
    hexagonal* m_water[42];
};
#endif // GROUND_H
