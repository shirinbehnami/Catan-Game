#include "sourcecard.h"

SourceCard::SourceCard(State state,QWidget *parent)
    :cards(parent),
      m_state(state)
{

    setFlat(true);
    setMinimumSize(QSize(80,150));
    setIconSize(QSize(70,210));

    this->updatecard(m_state);

    connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatecard(State)));
}

SourceCard::SourceCard(QString s,QWidget *parent)
    :cards(parent)
{
    if(s=="wheat")
        m_state = SourceCard::wheat;
    else if(s=="clay")
        m_state = SourceCard::clay;
    else if(s=="ore")
        m_state = SourceCard::ore;
    else if(s=="wood")
        m_state = SourceCard::wood;
    else if(s=="sheep")
        m_state = SourceCard::sheep;


    setFlat(true);
    setMinimumSize(QSize(80,150));
    setIconSize(QSize(70,210));

    this->updatecard(m_state);

    connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatecard(State)));
}
SourceCard::~SourceCard() {
}

void SourceCard::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

QString SourceCard::get_state(){
    switch (m_state) {
    case SourceCard::wheat:
        return "wheat";
    case SourceCard::clay:
        return "clay";
    case SourceCard::ore:
        return "ore";
    case SourceCard::wood:
        return "wood";
    case SourceCard::sheep:
        return "sheep";
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
