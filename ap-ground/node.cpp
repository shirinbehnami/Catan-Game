#include "node.h"

node::node(QWidget *parent)
    : QPushButton(parent),
      m_row(0), m_col(0)
{
   // this->updatenode(m_state);
    //QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatenode(State)));
}

node::~node() {}

void node::setState(State state) {
    if (m_state != state) {
        m_state = state;
       // emit stateChanged(state);
    }
}

QPixmap node::stateToPixmap(State state) {
    switch (state) {
        case node::byaban:
            return QPixmap(":/image/byaban.jpg");
        case node::gandom:
            return QPixmap(":/image/gandom.jpg");
        case node::agor:
            return QPixmap(":/image/agor.jpg");
        case node::sang:
            return QPixmap(":/image/sang.jpg");
        case node::chob:
            return QPixmap(":/image/chob.jpg");
        case node::gosepand:
            return QPixmap(":/image/gosepand.jpg");
        default:
            return QPixmap();
    }

}

void node::updatenode(State state) {
    this->setIcon(node::stateToPixmap(state));
}
