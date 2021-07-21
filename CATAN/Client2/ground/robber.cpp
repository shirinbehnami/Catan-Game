#include "robber.h"

#include <QDebug>

int robber::robber_index = 0;

robber::robber(int id,QWidget *parent)
      : QPushButton(parent),
        m_state(robber::none),
        index(id)
{
    this->updaterobber(m_state);

    connect(this, SIGNAL(stateChanged(State)), this, SLOT(updaterobber(State)));
}

robber::~robber()
{
}

void robber::setState(State state) {
        m_state = state;
        if(m_state==robber::Robber)
        {
            robber::robber_index = index;
        }
        emit stateChanged(state);
}

QPixmap robber::stateToPixmap(State state) {
    switch (state) {
        case robber::Robber:
            return QPixmap(":/image/robber.png");
        default:
            return QPixmap();
    }

}

void robber::updaterobber(State state) {
    this->setIcon(robber::stateToPixmap(state));
}
