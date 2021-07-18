#include "node.h"

node::node(QWidget *parent)
    : QPushButton(parent),
      m_state(none)
{
    this->updatenode(m_state,"");
    QObject::connect(this, SIGNAL(stateChanged(State,QString)), this, SLOT(updatenode(State,QString)));


}

node::~node() {}

void node::setState(State state,QString s) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state,s);
    }
}

QPixmap node::stateToPixmap(State state,QString s) {
    switch (state) {
        case node::house:
            return QPixmap(":/image/node/house"+s+".png");
        case node::city:
            return QPixmap(":/image/node/city"+s+".png");
        default:
            return QPixmap();
    }

}

void node::updatenode(State state,QString s) {
    this->setIcon(node::stateToPixmap(state,s));
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
