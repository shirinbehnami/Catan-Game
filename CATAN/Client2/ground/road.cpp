#include "road.h"

roads::roads(State s,Type t,QWidget *parent)
    : QPushButton(parent),
      m_state(s),
      m_type(t),
      is_built(false)
{
    this->updateroad(none);
    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateroad(State)));
}

roads::~roads() {}

void roads::setState() {
     is_built = true;
     emit stateChanged(m_state);
}

QPixmap roads::stateToPixmap(State state) {
    switch (state) {
        case roads::thirty:
            return QPixmap(":/image/road/thirty"+color+".png");
        case roads::thirtyNeg:
            return QPixmap(":/image/road/thirtyNeg"+color+".png");
        case roads::ninety:
            return QPixmap(":/image/road/ninety"+color+".png");
        default:
            return QPixmap();
    }

}

void roads::updateroad(State state) {
    this->setIcon(roads::stateToPixmap(state));
}
