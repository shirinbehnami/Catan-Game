#include "specialscorecard.h"

SpecialScorecard::SpecialScorecard(State state)
    : m_state(state)
{
    this->setIcon(SpecialScorecard::stateToPixmap(m_state));
}


SpecialScorecard::~SpecialScorecard() {}

QPixmap SpecialScorecard::stateToPixmap(State state) {
    switch (state) {
        case SpecialScorecard::Knight:
            return QPixmap(":/image/cards/Knight.png");
        case SpecialScorecard::RoadBuilder:
            return QPixmap(":/image/cards/RoadBuilder.png");
        default:
            return QPixmap();
    }

}
