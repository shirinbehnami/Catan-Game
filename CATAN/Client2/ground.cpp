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


    this->adjustSize();

    string s1,s2;
    int end= s.find('-');
    s1=s.substr(0,end);
    s2=s.substr(end+1,s.length());

    qDebug()<<s1.c_str();
    qDebug()<<s2.c_str();

    setResources(s1);
    setnumbers(s2);



 }

ground::~ground()
{
    delete ui;
}

void ground::setResources(string s)
{
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
           break;
       }
   }
}
void ground::setnumbers(string s)
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

            labels[i]->setText(QString::number(x));
            qDebug()<<QString::number(i)<<"----------"<<QString::number(x);
        }
        else
            s=s.substr(2,s.length());
    }
}
