#include "hexagonal.h"

hexagonal::hexagonal(QWidget *parent)
    : QPushButton(parent),
      m_row(0), m_col(0),
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

QPixmap hexagonal::stateToPixmap(State state) {
    switch (state) {
        case hexagonal::desert:
            return QPixmap(":/image/desert.jpg");
        case hexagonal::wheat:
            return QPixmap(":/image/wheat.jpg");
        case hexagonal::clay:
            return QPixmap(":/image/clay.jpg");
        case hexagonal::ore:
            return QPixmap(":/image/ore.jpg");
        case hexagonal::wood:
            return QPixmap(":/image/wood.jpg");
        case hexagonal::sheep:
            return QPixmap(":/image/sheep.jpg");
        case hexagonal::water:
            return QPixmap(":/image/water.jpg");
        default:
            return QPixmap();
    }

}

void hexagonal::updateHexagonal(State state) {
    this->setIcon(hexagonal::stateToPixmap(state));
}
