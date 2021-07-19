#ifndef ROAD_H
#define ROAD_H

#include<QPushButton>
#include <QObject>

class roads:public QPushButton
{

    Q_OBJECT

public:
    enum State {
        thirty,
        ninety,
        thirtyNeg,
        none
    };
    Q_ENUM(State)

    enum Type{
        bridge,
        road
    };
    Q_ENUM(Type)

    explicit roads(State s,Type t,QWidget *parent = nullptr);
    virtual ~roads();

    State state() const { return m_state; }
    void setState();

    void set_index(int i){index=i;}
    int get_index(){return index;}

    void set_color(QString s){color=s;}
    QString get_color(){return color;}

    bool get_is_built(){return is_built;}
    void set_is_built(bool x){is_built=x;}

signals:
    void stateChanged(State State);

private:
    int index;
    State m_state;
    QString color;
    Type m_type;
    bool is_built;

    QPixmap stateToPixmap(State state);

private slots:
    void updateroad(State state);
};

#endif // ROAD_H
