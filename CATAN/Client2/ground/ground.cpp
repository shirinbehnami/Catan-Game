#include "ground.h"
#include "ui_ground.h"

#include <algorithm>

ground::ground(int pl_num,string s,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ground)
{
    ui->setupUi(this);
    this->setWindowTitle("ground"+QString::number(pl_num));
    set_city_colors();

    set_hexagonal();

    set_road(pl_num);

    set_node(pl_num);

    string s1,s2;
    int end= s.find('-');
    s1=s.substr(0,end);
    s2=s.substr(end+1,s.length());

    int desert_num=setResources(s1);
    setnumbers(s2,desert_num);
    setwidgets();
    create_node_neighberhood();

    this->adjustSize();
//-------------------SIGNALS---------------------------
    connect(nextturn,SIGNAL(clicked()),this,SLOT(next_turn_pressed()));
    connect(rollbtn,SIGNAL(clicked()),this,SLOT(roll()));
 }

ground::~ground()
{
    delete ui;
}

void ground::set_hexagonal()
{
    for (int id = 0; id < hex_num; ++id)
    {
        hexagonal* hex = this->findChild<hexagonal*>(QString("hex%1").arg(id));
        Q_ASSERT(hex != nullptr);

        m_hexagonal[id] = hex;

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

}
void ground::set_node(int pl_num)
{
    for (int id = 0; id < nodes_num; ++id)
    {
        m_nodes[id]=new node(this);
        m_nodes[id]->setState(node::none);
        m_nodes[id]->setEnabled(false);
        m_nodes[id]->setVisible(false);
        m_nodes[id]->set_index(id);

        QObject::connect(m_nodes[id], &QPushButton::pressed, this,
                [=]() { ChangeShapenode(pl_num); });
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
}
void ground::set_road(int pl_num)
{
     for(int i=40; i<road_num;i++)
     {
         if(i>=40 && i<44)
         {
            if(i%2==0)
                m_roads[i]=new roads(roads::thirty,roads::road,this);
            else
                m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

            m_roads[i]-> setGeometry(255+((i-40)*42.25), 97, 16, 16);
         }
         if(i>=44 && i<46)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirty,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

              m_roads[i]->setGeometry(255+((i+2-40)*42.25), 97, 16, 16);
         }
         if(i>=46 && i<50)
         {
            if(i%2==0)
                m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
            else
                m_roads[i]=new roads(roads::thirty,roads::road,this);

            m_roads[i]-> setGeometry(255+((i-46)*42.25), 168, 16, 16);
         }
         if(i>=50 && i<55)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(255+((i+2-46)*42.25), 168, 16, 16);
         }
         if(i>=55 && i<61)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(255+((i-55)*42.25), 240, 16, 16);
         }
         if(i>=61 && i<65)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirty,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(255+((i+1-55)*42.25), 240, 16, 16);
         }
         if(i>=65 && i<73)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(213+((i-65)*42.25), 312, 16, 16);
         }
         if(i>=73 && i<76)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirty,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(213+((i+1-65)*42.25), 312, 16, 16);
         }
         if(i>=76 && i<86)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirty,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(171+((i-76)*42.25), 382, 16, 16);
         }
         if(i>=86 && i<88)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(171+((i+1-76)*42.25), 382, 16, 16);
         }
         if(i>=88 && i<98)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(171+((i-88)*42.25), 454, 16, 16);
         }
         if(i>=98 && i<100)
         {
             if(i%2==0)
                  m_roads[i]=new roads(roads::thirty,roads::road,this);
              else
                  m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(171+((i+1-88)*42.25), 454, 16, 16);
         }
         if(i>=100 && i<108)
         {
             if(i%2==0)
                 m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);
             else
                 m_roads[i]=new roads(roads::thirty,roads::road,this);

             m_roads[i]->setGeometry(213+((i-100)*42.25), 526, 16, 16);
         }
         if(i>=108 && i<111)
         {
             if(i%2==0)
                  m_roads[i]=new roads(roads::thirty,roads::road,this);
              else
                  m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(213+((i+1-100)*42.25), 526, 16, 16);
         }
         if(i>=111 && i<117)
         {
             if(i%2==0)
                  m_roads[i]=new roads(roads::thirty,roads::road,this);
              else
                  m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(255+((i-111)*42.25), 600, 16, 16);
         }
         if(i>=117 && i<119)
         {
             if(i%2==0)
                  m_roads[i]=new roads(roads::thirty,roads::road,this);
              else
                  m_roads[i]=new roads(roads::thirtyNeg,roads::road,this);

             m_roads[i]->setGeometry(255+((i+2-111)*42.25), 600, 16, 16);
         }
     }

     for(int i=0; i<5;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(234+(i*84.5), 133, 16, 16);
     }
     m_roads[5]=new roads(roads::ninety,roads::road,this);
     m_roads[5]->setGeometry(530, 206, 16, 16);
     m_roads[6]=new roads(roads::ninety,roads::road,this);
     m_roads[6]->setGeometry(613, 206, 16, 16);
     m_roads[7]=new roads(roads::ninety,roads::road,this);
     m_roads[7]->setGeometry(700, 206, 16, 16);
     for(int i=8; i<14;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(233+((i-8)*84.5), 280, 16, 16);
     }
     for(int i=14; i<21;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(193+((i-14)*84.5), 354, 16, 16);
     }
     for(int i=21; i<27;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(149+((i-21)*84.5), 420, 16, 16);
     }
     for(int i=27; i<34;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(190+((i-27)*84.5), 492, 16, 16);
     }
     for(int i=34; i<40;i++)
     {
         m_roads[i]=new roads(roads::ninety,roads::road,this);
         m_roads[i]-> setGeometry(236+((i-34)*84.5), 567, 16, 16);
     }

     for (int id = 0; id < road_num; ++id)
     {
        m_roads[id]->setStyleSheet("border:none;outline:none;color:white;");
        m_roads[id]->setMinimumSize(QSize(40,70));
        m_roads[id]->setIconSize(QSize(50,50));
        m_roads[id]->setEnabled(false);
        m_roads[id]->set_index(id);

        connect(m_roads[id], &roads::clicked, this,[=]() { ChangeShaperoad(pl_num); });
     }
}
//void ground::set_bridge();

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
            //qDebug()<<QString::number(i)<<"----------"<<QString::number(x);
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
    int s=10*a+b;
    emit roll_pressed(s);
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
    rollbtn->setEnabled(false);

    nextturn=new QPushButton(this);
    nextturn-> setGeometry(950,580,100,40);
    nextturn->setText("Next Turn");
    nextturn->setStyleSheet("background-color:rgb(208,22,53);");

    QLabel* l1;
    l1=new QLabel(this);
    l1-> setGeometry(QRect(950, 375, 375, 125));
    l1->setStyleSheet("background-color:rgb(181,144,246);");
}
void ground::enabel_nodes()
{
    for (int id = 0; id < nodes_num; ++id)
    {
        m_nodes[id]->setEnabled(true);
        m_nodes[id]->setVisible(true);
    }
}
void ground::disabel_nodes()
{
    for (int id = 0; id < nodes_num; ++id)
        if(!m_nodes[id]->get_is_built())
        {
            m_nodes[id]->setEnabled(false);
            m_nodes[id]->setVisible(false);
        }
    show();
    qApp->processEvents();
}
void ground::update_node(int k,int pl_num)
{
    m_nodes[k]->setStyleSheet("border: none;outline: none");
    m_nodes[k]->setIconSize(QSize(70,70));
    m_nodes[k]->setMinimumSize(QSize(40,45));
    m_nodes[k]->setGeometry(m_nodes[k]->x()-20,m_nodes[k]->y()-20,m_nodes[k]->width(),m_nodes[k]->height());
    m_nodes[k]->set_is_built(true);

    if(pl_num==1)
    {
        m_nodes[k]->set_color("yellow");
        m_nodes[k]->setState(node::house);
    }
    else if(pl_num==2)
    {
        m_nodes[k]->set_color("red");
        m_nodes[k]->setState(node::house);
    }

    else if(pl_num==3)
    {
        m_nodes[k]->set_color("blue");
        m_nodes[k]->setState(node::house);
    }

    else
    {
        m_nodes[k]->set_color("green");
        m_nodes[k]->setState(node::house);
    }
    m_nodes[k]->set_is_built(true);
    m_nodes[k]->setVisible(true);
    m_nodes[k]->setEnabled(true);
}
void ground::enabel_roads()
{
    for (int id = 0; id < road_num; ++id)
    {
        m_roads[id]->setEnabled(true);
    }
}
void ground::disabel_roads()
{
    for (int id = 0; id < road_num; ++id)
    {
        if(!m_roads[id]->get_is_built())
        {
            m_roads[id]->setEnabled(false);
        }
    }
}
void ground::update_roads(int k, int pl_num)
{

    if(pl_num==1)
    {
        m_roads[k]->set_color("yellow");
        m_roads[k]->setState();
    }
    else if(pl_num==2)
    {
        m_roads[k]->set_color("red");
        m_roads[k]->setState();
    }
    else if(pl_num==3)
    {
        m_roads[k]->set_color("blue");
        m_roads[k]->setState();
    }
    else
    {
        m_roads[k]->set_color("green");
        m_roads[k]->setState();
    }
    m_roads[k]->set_is_built(true);
    m_roads[k]->setEnabled(true);

}
void ground::disabel_dice(){rollbtn->setEnabled(false);}
void ground::enabel_dice(){rollbtn->setEnabled(true);}
void ground::set_city_colors()
{
    for(int i=0;i<4;i++)
        {city_colors[i]=new QString();
    switch(i+1)
    {
    case(1):
        *city_colors[i]="yellow";
        break;
    case(2):
        *city_colors[i]="red";
        break;
    case(3):
        *city_colors[i]="blue";
        break;
    case(4):
        *city_colors[i]="green";
        break;
    }
    }
}
void ground::ChangeShapenode(int pl_num)
{
     node* BT=(node*)sender();
    if(check_node(BT,pl_num))
    {
         BT->setStyleSheet("border: none;outline: none");
         BT->setIconSize(QSize(70,70));
         BT->setMinimumSize(QSize(40,45));
         BT->setGeometry(BT->x()-20,BT->y()-20,BT->width(),BT->height());

         if(pl_num==1)
         {
             BT->set_color("yellow");
             BT->setState(node::house);
         }
         else if(pl_num==2)
         {
             BT->set_color("red");
             BT->setState(node::house);
         }
         else if(pl_num==3)
         {
             BT->set_color("blue");
             BT->setState(node::house);
         }
         else
         {
             BT->set_color("green");
             BT->setState(node::house);
         }

         emit ColorShapenode();
         emit obj_created(BT->get_index());
    }
    else
        QMessageBox::information(this, tr("error"),"you can't build in this position");
}
void ground::ChangeShaperoad(int pl_num)
{
    roads* BT=(roads*)sender();
    //if(check_node(BT,pl_num))
    //{
     if(pl_num==1)
     {
         BT->set_color("yellow");
         BT->setState();
     }
     else if(pl_num==2)
     {
         BT->set_color("red");
         BT->setState();
     }
     else if(pl_num==3)
     {
         BT->set_color("blue");
         BT->setState();
     }
     else
     {
         BT->set_color("green");
         BT->setState();
     }

     emit ColorShaperoad();
     emit obj_created(BT->get_index());
    //}
    //else
        //QMessageBox::information(this, tr("error"),"you can't build in this position");
}
void ground::next_turn_pressed()
{
    emit turn_pressed();
}

void ground::Card_distribution(Player* p)
{
    string s=p->get_obj_built().toStdString();
    int end= s.find('-');
    int index;
    sscanf(s.substr(0,end).c_str(), "%d", &index);

    int cnt=0;
    for (int i=0;i<hex_num;i++)
    {
         if(std::find(hex_neighberhood[i].begin(),hex_neighberhood[i].end(),index)!=hex_neighberhood[i].end())
         {
             cnt++;
             QString s = m_hexagonal[i]->getState();

             if(s!="desert")
             {
                 cards* c = new SourceCard(s,this);
                 c->show();
                 p->Addcard(c);
             }
         }
         if(cnt==3)
         {
             break;
         }
    }

}
void ground::Card_distribution(Player* p,int sum)
{

    QString roll_num = QString::number(sum);

    for (int i=0;i<hex_num;i++)
    {
         if(labels[i]->text()==roll_num)
         {
             for(int j=0;j<hex_neighberhood[i].size();j++)
             {
                 if(m_nodes[hex_neighberhood[i][j]]->get_state()!="none" && m_nodes[hex_neighberhood[i][j]]->get_color()==p->get_string_color())
                 {
                     QString s = m_hexagonal[i]->getState();

                     if(s!="desert")
                     {
                         cards* c = new SourceCard(s,this);
                         c->show();
                         p->Addcard(c);
                     }
                 }
             }
         }
    }
}

bool ground::check_node(node* n,int pl_num)
{
    if(n->get_color()!="")
        return false;
    vector<int> V=node_neighberhood[n->get_index()];
    for(auto &p:V)
    {
        qDebug()<<"p is:"+QString::number(p);
        if(m_nodes[p]->get_color()==(*city_colors[pl_num-1]))
            return false;
    }
    return true;

}
void ground::create_node_neighberhood()
{
    for(const auto &p:hex_neighberhood)
    {
        vector<int>V=p.second;
        for(int i=1;i<6;i++)
        {
            int val=V[i];
            int val2=V[i-1];
            node_neighberhood[val].push_back(val2);
            node_neighberhood[val2].push_back(val);
        }
        node_neighberhood[V[0]].push_back(V[5]);
        node_neighberhood[V[5]].push_back(V[0]);
    }
    //remove repititions
    for(auto &p:node_neighberhood)
    {
        vector<int>::iterator ip;
        ip=unique(p.second.begin(),p.second.begin()+p.second.size());
        p.second.resize(distance(p.second.begin(),ip));
    }
}
