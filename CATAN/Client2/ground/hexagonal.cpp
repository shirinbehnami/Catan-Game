#include "hexagonal.h"

hexagonal::hexagonal(QWidget *parent)
    : QPushButton(parent),
      m_state(hexagonal::water)
{
    this->updateHexagonal(m_state);

    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateHexagonal(State)));

}


hexagonal::~hexagonal() {
}

void hexagonal::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}
QString hexagonal::getState()
{
    switch (m_state) {
    case desert:
        return "desert";
    case wheat:
        return "wheat";
    case clay:
        return "clay";
    case ore:
        return "ore";
    case wood:
        return "wood";
    case water:
        return  "water";
    case sheep:
        return "sheep";
    }
}

QPixmap hexagonal::stateToPixmap(State state) {
    switch (state) {
        case hexagonal::desert:
            return QPixmap(":/image/hexagonal/desert.jpg");
        case hexagonal::wheat:
            return QPixmap(":/image/hexagonal/wheat.jpg");
        case hexagonal::clay:
            return QPixmap(":/image/hexagonal/clay.jpg");
        case hexagonal::ore:
            return QPixmap(":/image/hexagonal/ore.jpg");
        case hexagonal::wood:
            return QPixmap(":/image/hexagonal/wood.jpg");
        case hexagonal::sheep:
            return QPixmap(":/image/hexagonal/sheep.jpg");
        case hexagonal::water:
            return QPixmap(":/image/hexagonal/water.jpg");
        default:
            return QPixmap();
    }
}

void hexagonal::updateHexagonal(State state) {
    this->setIcon(hexagonal::stateToPixmap(state));
}
