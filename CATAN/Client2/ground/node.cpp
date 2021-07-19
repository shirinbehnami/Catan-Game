#include "node.h"

node::node(QWidget *parent)
    : QPushButton(parent),
      m_state(none),
      is_built(false)
{
    this->updatenode(m_state);
    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatenode(State)));


}

node::~node() {}

void node::setState(State state) {
    if (m_state != state) {
        m_state = state;
        is_built=true;
        emit stateChanged(state);
    }
}

QPixmap node::stateToPixmap(State state) {
    switch (state) {
        case node::house:
            return QPixmap(":/image/node/house"+color+".png");
        case node::city:
            return QPixmap(":/image/node/city"+color+".png");
        default:
            return QPixmap();
    }

}

void node::updatenode(State state) {
    this->setIcon(node::stateToPixmap(state));
}

QString node::get_state()
{    switch (m_state) {
    case node::house:
        return "house";
    case node::city:
        return "city";
    default:
        return "none";
}

}
