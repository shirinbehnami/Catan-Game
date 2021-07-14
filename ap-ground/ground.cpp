#include "ground.h"
#include "ui_ground.h"
#include "node.h"
<<<<<<< HEAD
#include "sourcecard.h"

=======
#include<QPainter>
>>>>>>> 9f938246a3f9f4305bfe59badc7243ffe9ddd77c
#include <QSize>

ground::ground(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ground)
{
    ui->setupUi(this);
    setwidgets();
    for (int id = 0; id < hex_num; ++id)
    {
        hexagonal* hex = this->findChild<hexagonal*>(QString("hex%1").arg(id));
        Q_ASSERT(hex != nullptr);

        m_hexagonal[id] = hex;
        //QObject::connect(hex, SIGNAL(clicked(bool)), map, SLOT(map()));
        labels[id]=new QLabel(this);
        labels[id]-> setGeometry(QRect(m_hexagonal[id]->x()+40, m_hexagonal[id]->y()+50, 40, 30));
        labels[id]->setStyleSheet("color:white;font:bold;""font-size:25px;");
    }

    for (int id = 0; id < water_num; ++id)
    {
        hexagonal* w = this->findChild<hexagonal*>(QString("water%1").arg(id));
        Q_ASSERT(w != nullptr);

        m_water[id] = w;
    }


    for (int id = 0; id < nodes_num; ++id)
    {
        m_nodes[id]=new node(this);
        Q_ASSERT(m_nodes[id] != nullptr);
       // m_nodes[id]->setStyleSheet("border: none;outline: none");
       // m_nodes[id]->setFlat(true);
       // m_nodes[id]->setMinimumSize(QSize(25,30));
        //m_nodes[id]->setIconSize(QSize(40,40));
        //m_nodes[id]->setState(node::house);
        m_nodes[id]->setStyleSheet("background-color:red;");
    }

    int c;
    int idx=0;
    for(int j=0;j<4;j++)
    {for(int i=0;i<(11+2*j);i++)
       {
        if(i%2)
            c=-1;
        else
            c=0;
           m_nodes[idx]-> setGeometry(295-((j+1)*42.5)+i*42.5, 140+(j*73)+c*22, 12, 12);
        idx++;
        }
    }
    for(int j=0;j<4;j++)
    {for(int i=0;i<=(16-2*j);i++)
       {
        if(i%2)
            c=-1;
        else
            c=0;
         m_nodes[idx]-> setGeometry(295+((j-4)*42.5)+i*42.5, 140+((j+3)*73+48)-c*22, 12, 12);
         idx++;
        }
    }


<<<<<<< HEAD

    cr.push_back(new SourceCard(SourceCard::clay,this));
    cr.push_back(new SourceCard(SourceCard::ore,this));
    cr.push_back(new SourceCard(SourceCard::ore,this));
    cr.push_back(new SourceCard(SourceCard::sheep,this));

    cr[0]->setGeometry(900,250,12,12);
    cr[1]->setGeometry(950,250,12,12);
    cr[2]->setGeometry(1000,250,12,12);
    cr[3]->setGeometry(1050,250,12,12);

    for(int i=0;i<cr.size();i++)
    {
        cr[i]->setFlat(true);
        cr[i]->setMinimumSize(QSize(80,150));
        cr[i]->setIconSize(QSize(70,210));
    }
        this->adjustSize();
=======
    this->adjustSize();
>>>>>>> 9f938246a3f9f4305bfe59badc7243ffe9ddd77c
    int desert_index=makeground();
    setnumbers(desert_index);
    QPainter p;
    p.drawLine(m_nodes[0]->x(),m_nodes[0]->y(),m_nodes[1]->x(),m_nodes[1]->y());
    //----------------------------------------------------------------------------------------------------------
    //Signals
    connect(rollbtn,SIGNAL(released()),this,SLOT(roll()));
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
    vector<int> numbers_islands={11,2,4,5,9,10,10};//+6,8
   random_shuffle(indexes.begin(),indexes.end());
   vector<int> V;
   //6
   final[indexes[0]]=6;
   V.push_back(indexes[0]);
   //8
   int numberof8=0,numberof6=0;
    for(int i=1;i<18 && (numberof8!=2 || numberof6!=1);i++)
    {
        bool flag=true;
        for(vector<int>::iterator j=V.begin();j!=V.end();j++)
        {   int T;
            *j>9?T=18-(*j):T=(*j);
            for(vector<int>::iterator it=neighbers[T].begin();it!=neighbers[T].end();it++)
                if(*j>9)
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
           {
            if(numberof6==0)
               {final[indexes[i]]=6;
                numberof6++;
             }
            else
            {
             final[indexes[i]]=8;
             numberof8++;
            }
            V.push_back(indexes[i]);
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
    int X=rand()%8+19;
    int Y=rand()%(28-X-2)+2;
    if(rand()%2)
    { final[X]=6;
      final[X+Y]=8;
    }
    else
    { final[X]=8;
      final[X+Y]=6;
    }
    //other numbers
    random_shuffle(numbers_islands.begin(),numbers_islands.end());
    j=0;
    for(int i=19;i<hex_num;i++)
        if(final[i]==-1)
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
void ground::setdice(int a,int b)
{
    QString A="url(:/image/dice/"+QString::number(a)+".png);";
    QString B="url(:/image/dice/"+QString::number(b)+".png);";
    if(!a and !b)
    {
    dice[0]->setStyleSheet("QLabel{"
                               "background-image:url(:/image/dice/1.png);"
                               "background-position:center;"
                               "background-origin:content;"
                               "background-repeat:none;"
                               "}");

        dice[1]->setStyleSheet("QLabel{"
                                   "background-image:url(:/image/dice/1.png);"
                                   "background-position:center;"
                                   "background-origin:content;"
                                   "background-repeat:none;"
                                   "}");

    }
    else
    {
        dice[0]->setStyleSheet("QLabel{"
                                   "background-image:"+A
                                   +"background-position:center;"
                                   "background-origin:content;"
                                   "background-repeat:none;"
                                   "}");
        dice[1]->setStyleSheet("QLabel{"
                                       "background-image:"+B
                                       +"background-position:center;"
                                       "background-origin:content;"
                                       "background-repeat:none;"
                                       "}");


    }


}
void ground::roll()
{
    srand(time(0));
    int a=rand()%6+1;
    int b=rand()%6+1;
    setdice(a,b);
}
void ground::setwidgets()
{
    dice[0]=new QLabel(this);
    dice[1]=new QLabel(this);
    dice[0]->setGeometry(1200,520,125,125);
    dice[1]->setGeometry(1060,520,125,125);
    setdice(0,0);

    rollbtn=new QPushButton(this);
    rollbtn->setGeometry(950,520,100,40);
    rollbtn->setText("Roll!");
    rollbtn->setStyleSheet("background-color:rgb(181,144,246);");

    nextturn=new QPushButton(this);
    nextturn-> setGeometry(950,580,100,40);
    nextturn->setText("Next Turn");
    nextturn->setStyleSheet("background-color:rgb(208,22,53);");
}
