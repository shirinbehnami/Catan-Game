#include "ground.h"
#include "ui_ground.h"

#include <QMessageBox>
#include <QSignalMapper>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

ground::ground(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ground)
{
    ui->setupUi(this);

    QSignalMapper* map = new QSignalMapper(this);
    for (int id = 0; id < 19; ++id) {

        hexagonal* hex = this->findChild<hexagonal*>(QString("hex%1").arg(id));
        Q_ASSERT(hex != nullptr);

        m_hexagonal[id] = hex;
        map->setMapping(hex, id);
        QObject::connect(hex, SIGNAL(clicked(bool)), map, SLOT(map()));
    }


    this->adjustSize();
    makeground();

 }

ground::~ground()
{
    delete ui;
}

hexagonal* ground::hexagonalAt(int row, int col) const {
    if (row >= 0 && row < 3 &&
        col >= 0 && col < 3) {
        int index = row * 3 + col;
        return m_hexagonal[index];
    }
    else {
        return nullptr;
    }
}

void ground::makeground()
{
    srand(time(0));
   //1.chob  2.gosepand   3.sang    4.agor    5.gandom  6.byaban

    vector<int> vec={1,1,1,
                    2,2,2,
                    3,3,3,3,3,
                    4,4,4,
                    5,5,5,5,
                    6};


   random_shuffle(vec.begin(),vec.end());

   for(int i=0;i<19;i++)
   {
       switch (vec[i]) {
       case 1:
           m_hexagonal[i]->setState(hexagonal::chob);
           break;
       case 2:
           m_hexagonal[i]->setState(hexagonal::gosepand);
           break;
       case 3:
           m_hexagonal[i]->setState(hexagonal::sang);
           break;
       case 4:
           m_hexagonal[i]->setState(hexagonal::agor);
           break;
       case 5:
           m_hexagonal[i]->setState(hexagonal::gandom);
           break;
       case 6:
           m_hexagonal[i]->setState(hexagonal::byaban);
           break;
       }
   }
}
