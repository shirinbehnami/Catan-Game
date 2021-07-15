#include "ground.h"
#include "ui_ground.h"


ground::ground(string s,QWidget *parent)
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
        labels[id]->setStyleSheet("color:white;font:bold;" "font-size:25px;");
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
        m_nodes[id]->setStyleSheet("background-color:black;");
        m_nodes[id]->setEnabled(false);
        connect(m_nodes[id],SIGNAL(clicked()),m_nodes[id],SLOT(ChangeColor()));
    }

    int c;
    int idx=0;
    for(int j=0;j<4;j++)
        {
            for(int i=0;i<(11+2*j);i++)
           {
                if((j==0 && i!=5 && i!=9 && i!=10) || (j==1 && i!=0 && i!=6) || (j==2 && i!=0 && i!=1 && i!=14) || (j==3 && i!=0 && i!=1 && i!=15 && i!=16))
                {
                    if(i%2)
                        c=-1;
                    else
                        c=0;
                       m_nodes[idx]-> setGeometry(295-((j+1)*42.5)+i*42.5, 140+(j*73)+c*22, 12, 12);
                    idx++;
                }
            }
        }
        for(int j=0;j<4;j++)
        {
           for(int i=0;i<=(16-2*j);i++)
           {
               if((j==0 && i!=0 && i!=15 && i!=16) || (j==1 && i!=14) || (j==2) ||(j==3 && i!=7))
               {
                    if(i%2)
                        c=-1;
                    else
                        c=0;
                     m_nodes[idx]-> setGeometry(295+((j-4)*42.5)+i*42.5, 140+((j+3)*73+48)-c*22, 12, 12);
                     idx++;
               }
            }
        }
    this->adjustSize();

    string s1,s2;
    int end= s.find('-');
    s1=s.substr(0,end);
    s2=s.substr(end+1,s.length());

    qDebug()<<s1.c_str();
    qDebug()<<s2.c_str();

    int desert_num=setResources(s1);
    setnumbers(s2,desert_num);

//-------------------SIGNALS---------------------------

 }

ground::~ground()
{
    delete ui;
}

int ground::setResources(string s)
{
    int return_value;
   for(int i=0;i<hex_num;i++)
   {
       switch (s[i]) {
       case '1':
           m_hexagonal[i]->setState(hexagonal::wood);
           break;
       case '2':
           m_hexagonal[i]->setState(hexagonal::sheep);
           break;
       case '3':
           m_hexagonal[i]->setState(hexagonal::ore);
           break;
       case '4':
           m_hexagonal[i]->setState(hexagonal::clay);
           break;
       case '5':
           m_hexagonal[i]->setState(hexagonal::wheat);
           break;
       case '6':
           m_hexagonal[i]->setState(hexagonal::desert);
           return_value=i;
           break;
       }
   }
   return return_value;
}
void ground::setnumbers(string s,int desert_num)
{
    for(int i=0;i<hex_num;i++)
    {
        if(s[0]!=-1)
        {
            int end= s.find('-');
            string s1=s.substr(0,end);
            s=s.substr(end+1,s.length());
            int x;
            sscanf_s(s1.c_str(),"%d",&x);
            if(i!=desert_num)
                labels[i]->setText(QString::number(x));
            qDebug()<<QString::number(i)<<"----------"<<QString::number(x);
        }
        else
            s=s.substr(2,s.length());
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
void ground::enabel_nodes()
{
    for (int id = 0; id < nodes_num; ++id)
        m_nodes[id]->setEnabled(true);
}
void ground::update_node(int k)
{
    m_nodes[k]->setStyleSheet("background-color:red;");
}
