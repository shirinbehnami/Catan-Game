#include "sourcecard.h"
#include "QPushButton"

SourceCard::SourceCard(State state)
    :m_state(state)
{
    this->updatecard(m_state);

    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateHexagonal(State)));
}

SourceCard::~SourceCard() {
}

void SourceCard::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

QPixmap SourceCard::stateToPixmap(State state) {
    switch (state) {
        case SourceCard::wheat:
            return QPixmap(":/image/cards/Wheat.png");
        case SourceCard::clay:
            return QPixmap(":/image/cards/clay.png");
        case SourceCard::ore:
            return QPixmap(":/image/cards/ore.png");
        case SourceCard::wood:
            return QPixmap(":/image/cards/Wood.png");
        case SourceCard::sheep:
            return QPixmap(":/image/cards/Sheep.png");
        default:
            return QPixmap();
    }

}
