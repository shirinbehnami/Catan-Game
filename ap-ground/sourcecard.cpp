#include "sourcecard.h"
#include "QPushButton"

SourceCard::SourceCard(State state,QWidget *parent)
    :cards(parent),
      m_state(state)
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
            return QPixmap(":/image/cards/Wheat.jpg");
        case SourceCard::clay:
            return QPixmap(":/image/cards/clay.jpg");
        case SourceCard::ore:
            return QPixmap(":/image/cards/ore.jpg");
        case SourceCard::wood:
            return QPixmap(":/image/cards/Wood.jpg");
        case SourceCard::sheep:
            return QPixmap(":/image/cards/Sheep.jpg");
        default:
            return QPixmap();
    }

}

void SourceCard::updatecard(State state) {
    this->setIcon(SourceCard::stateToPixmap(state));
}
