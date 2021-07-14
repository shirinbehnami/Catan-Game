#include "specialscorecard.h"

SpecialScorecard::SpecialScorecard(State state)
    : m_state(state)
{
    this->setIcon(SpecialScorecard::stateToPixmap(m_state));
}


SpecialScorecard::~SpecialScorecard() {}

QPixmap SpecialScorecard::stateToPixmap(State state) {
    switch (state) {
        case SpecialScorecard::LargestArmy:
            return QPixmap(":/image/cards/LargestArmy.jpg");
        case SpecialScorecard::RoadBuilder:
            return QPixmap(":/image/cards/RoadBuilder.jpg");
        default:
            return QPixmap();
    }

}
