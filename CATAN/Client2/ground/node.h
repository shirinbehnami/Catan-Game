#ifndef NODE_H
#define NODE_H

#include<QPushButton>
#include <QObject>

class node:public QPushButton
{
    Q_OBJECT

public:
    enum State {
        house,
        none,
        city
    };
    Q_ENUM(State)

    explicit node(QWidget *parent = nullptr);
    virtual ~node();

    State state() const { return m_state; }
    void setState(State State);
    QString get_state();

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
    bool is_built;

    QPixmap stateToPixmap(State state);

private slots:
    void updatenode(State state);
};

#endif // NODEL_H
