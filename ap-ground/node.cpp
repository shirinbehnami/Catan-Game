#include "node.h"

node::node(QWidget *parent)
    : QPushButton(parent),
      m_row(0), m_col(0),
      m_state(house)
{
    this->setState(m_state);
    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatenode(State)));
}

node::~node() {}

void node::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

QPixmap node::stateToPixmap(State state) {
    switch (state) {
        case node::house:
            return QPixmap(":/image/house.jpg");
        case node::city:
            return QPixmap(":/image/city.jpg");
       // case node::none:
        //
        default:
            return QPixmap();
    }

}

void node::updatenode(State state) {
    this->setIcon(node::stateToPixmap(state));
}
