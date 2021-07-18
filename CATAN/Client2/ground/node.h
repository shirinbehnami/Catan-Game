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
    void setState(State State,QString s);
    QString get_state();

    void set_index(int i){index=i;}
    int get_index(){return index;}

    void set_color(QString s){color=s;}
    QString get_color(){return color;}

signals:
    void stateChanged(State State,QString s);

private:
    int index;
    State m_state;
    QString color;

    static QPixmap stateToPixmap(State state,QString s);

private slots:
    void updatenode(State state,QString s);
};

#endif // NODEL_H
