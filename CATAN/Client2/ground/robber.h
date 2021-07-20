#ifndef ROBBER_H
#define ROBBER_H

#include "hexagonal.h"
#include "ground.h"

#include<QPushButton>
#include <QObject>

class robber:public QPushButton
{   
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:

    enum State {
        Robber,
        none
    };
    Q_ENUM(State)

    explicit robber(int id,QWidget *parent = nullptr);
    virtual ~robber();

    void Do();

    State state() const { return m_state; }
    void setState(State State);

    static int getRobber_index(){return robber_index;}

signals:
    void stateChanged(State State);

private:
    State m_state;
    int index;
    static int robber_index;

    QPixmap stateToPixmap(State state);

private slots:
    void updaterobber(State state);
};

#endif // ROBBER_H
