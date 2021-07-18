#include "road.h"

road::road(QWidget *parent)
    : QPushButton(parent),
      m_state(none)
{
    this->updateroad(m_state);
    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateroad(State)));
}

road::~road() {}

void road::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

QPixmap road::stateToPixmap(State state) {
    switch (state) {
        case road::thirty:
            return QPixmap(":/image/road/thirtyblue.png");
        case road::thirtyNeg:
            return QPixmap(":/image/road/thirtyNegblue.png");
        case road::ninety:
            return QPixmap(":/image/road/ninetyblue.png");
        default:
            return QPixmap();
    }

}

void road::updateroad(State state) {
    this->setIcon(road::stateToPixmap(state));
}
