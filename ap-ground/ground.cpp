#include "ground.h"
#include "ui_ground.h"


ground::ground(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ground)
{
    ui->setupUi(this);
    for (int id = 0; id < hex_num; ++id)
    {
        hexagonal* hex = this->findChild<hexagonal*>(QString("hex%1").arg(id));
        Q_ASSERT(hex != nullptr);

        m_hexagonal[id] = hex;
        //QObject::connect(hex, SIGNAL(clicked(bool)), map, SLOT(map()));
        labels[id]=new QLabel(this);
        labels[id]-> setGeometry(QRect(m_hexagonal[id]->x()+40, m_hexagonal[id]->y()+50, 40, 30));
        labels[id]->setStyleSheet("color:white;font:bold;"
 "font-size:25px;");
    }

    for (int id = 0; id < water_num; ++id)
    {
        hexagonal* w = this->findChild<hexagonal*>(QString("water%1").arg(id));
        Q_ASSERT(w != nullptr);

        m_water[id] = w;
    }


    this->adjustSize();
    int desert_index=makeground();
    setnumbers(desert_index);

 }

ground::~ground()
{
    delete ui;
}

int ground::makeground()
{
    srand(time(0));
    int return_value;
    //first part
    //1.wood  2.sheep   3.ore    4.clay    5.wheat  6.desert
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
           m_hexagonal[i]->setState(hexagonal::wood);
           break;
       case 2:
           m_hexagonal[i]->setState(hexagonal::sheep);
           break;
       case 3:
           m_hexagonal[i]->setState(hexagonal::ore);
           break;
       case 4:
           m_hexagonal[i]->setState(hexagonal::clay);
           break;
       case 5:
           m_hexagonal[i]->setState(hexagonal::wheat);
           break;
       case 6:
           m_hexagonal[i]->setState(hexagonal::desert);
           return_value=i;
           break;
       }
   }

   //second part
   vec={1,1,
        2,2,
        3,3,
        4,4,
        5};


  random_shuffle(vec.begin(),vec.end());

  for(int i=0;i<hex_num-19;i++)
  {
      switch (vec[i]) {
      case 1:
          m_hexagonal[i+19]->setState(hexagonal::wood);
          break;
      case 2:
          m_hexagonal[i+19]->setState(hexagonal::sheep);
          break;
      case 3:
          m_hexagonal[i+19]->setState(hexagonal::ore);
          break;
      case 4:
          m_hexagonal[i+19]->setState(hexagonal::clay);
          break;
      case 5:
          m_hexagonal[i+19]->setState(hexagonal::wheat);
          break;
      case 6:
          m_hexagonal[i+19]->setState(hexagonal::desert);
          break;
      }
  }
  return return_value;
}
void ground::setnumbers(int desert_index)
{
    srand(time(0));
    //------------------------------------------------------------------------------------------------------
    //first part
    vector< vector<int> > neighbers={
       /*0*/ {1,3,4},
       /*1*/ {0,4,5,2},
       /*2*/ {1,5,6},
       /*3*/ {0,4,7,8},
       /*4*/ {0,1,3,5,8,9},
       /*5*/ {1,2,4,6,9,10},
       /*6*/ {2,5,10,11},
       /*7*/ {3,8,12},
       /*8*/ {3,4,7,9,12,13},
       /*9*/ {4,5,8,10,13,14},
    };
    vector<int> indexes;
    vector<int> final;
    for(int i=0;i<hex_num;i++)
     {   if(i!=desert_index && i<19)
            indexes.push_back(i);
        final.push_back(-1);
     }
    vector<int> numbers={2,
                        12,
                        3,3,3,
                        4,4,
                        5,5,
                        9,9,
                        10,
                        11,11};//+6,6,8,8
    vector<int> numbers_islands={2,4,5,9,10,10,11};//+6,8
   random_shuffle(indexes.begin(),indexes.end());
   //6
   final[indexes[0]]=6;
   final[indexes[1]]=6;
   //8
   int numberof8=0;
    for(int i=0;i<19 && numberof8!=2;i++)
    {
        bool flag=true;
        for(int j=0;j<2 && flag;j++)
        {   int T;
            indexes[j]>9?T=18-indexes[j]:T=indexes[j];
            for(vector<int>::iterator it=neighbers[T].begin();it!=neighbers[T].end();it++)
                if(indexes[j]>9)
                {if(*it==18-indexes[i])
                    {
                        flag=false;
                        break;
                    }
                }
                else
                {if(*it==indexes[i])
                    {
                        flag=false;
                        break;
                    }
                }

        }
        if(flag && final[indexes[i]]==-1)
           {final[indexes[i]]=8;
            numberof8++;
        }
    }
    //other numbers
    int j=0;
    for(int i=0;i<19;i++)
        if(final[indexes[i]]==-1 && indexes[i]!=desert_index)
        {
            final[indexes[i]]=numbers[j];
            j++;
        }
    //-----------------------------------------------------------------------------------------------------
    //second part
    //6,8
    int X=rand()%6+19;
    int Y=rand()%(28-X-2)+2;
    if(rand()%2)
    { final[X]=6;
      final[X+Y]=8;
    }
    else
    { final[X]=8;
      final[X+Y]=6;
    }
    random_shuffle(numbers_islands.begin(),numbers_islands.end());
    j=0;
    for(int i=19;i<hex_num;i++)
        if(final[i]==-1 && i!=desert_index)
        {
            final[i]=numbers_islands[j];
            j++;
        }


    setnumbers(final);
}
void ground::setnumbers(vector<int>final)
{
    for(int i=0;i<hex_num;i++)
        if(final[i]!=-1)
    {
        labels[i]->setText(QString::number(final[i]));
        qDebug()<<QString::number(i)<<"----------"<<QString::number(final[i]);
        }
}