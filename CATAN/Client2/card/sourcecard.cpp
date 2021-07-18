#include "sourcecard.h"

SourceCard::SourceCard(State state,QWidget *parent)
    :cards(parent),
      m_state(state)
{
    this->updatecard(m_state);

    connect(this, SIGNAL(stateChanged(State)), this, SLOT(updatecard(State)));
}

SourceCard::SourceCard(QString s,QWidget *parent)
{
    if(s=="wheat")
        SourceCard(SourceCard::wheat,parent);
    else if(s=="clay")
        SourceCard(SourceCard::clay,parent);
    else if(s=="ore")
        SourceCard(SourceCard::ore,parent);
    else if(s=="wood")
        SourceCard(SourceCard::wood,parent);
    else if(s=="sheep")
        SourceCard(SourceCard::sheep,parent);
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
