#include "hexagonal.h"

hexagonal::hexagonal(QWidget *parent)
    : QPushButton(parent),
      m_row(0), m_col(0)//,
      //m_state(hexagonal::sang)
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
        case hexagonal::byaban:
            return QPixmap(":/image/byaban.jpg");
        case hexagonal::gandom:
            return QPixmap(":/image/gandom.jpg");
        case hexagonal::agor:
            return QPixmap(":/image/agor.jpg");
        case hexagonal::sang:
            return QPixmap(":/image/sang.jpg");
        case hexagonal::chob:
            return QPixmap(":/image/chob.jpg");
        case hexagonal::gosepand:
            return QPixmap(":/image/gosepand.jpg");
        default:
            return QPixmap();
    }

}

void hexagonal::updateHexagonal(State state) {
    this->setIcon(hexagonal::stateToPixmap(state));
}
