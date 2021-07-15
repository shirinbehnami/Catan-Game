#include "specialscorecard.h"

QMap<QString,int> SpecialScoreCard::Cardholder;

SpecialScoreCard::SpecialScoreCard(State state,QWidget *parent)
    : cards(parent),
      m_state(state)
{
    this->setIcon(SpecialScoreCard::stateToPixmap(m_state));

    Cardholder.insert("WhereLargesArmy",0);
    Cardholder.insert("cntLargesArmy",2);
    Cardholder.insert("WhereRoadBuilder",0);
    Cardholder.insert("cntRoadBuilder",4);

}

QString SpecialScoreCard::get_state(){
    switch (m_state) {
    case SpecialScoreCard::LargestArmy:
        return "largestarmy";
    case SpecialScoreCard::RoadBuilder:
        return "roadbuilder";
    }
}

SpecialScoreCard::~SpecialScoreCard() {}

QPixmap SpecialScoreCard::stateToPixmap(State state) {
    switch (state) {
        case SpecialScoreCard::LargestArmy:
            return QPixmap(":/image/cards/LargestArmy.jpg");
        case SpecialScoreCard::RoadBuilder:
            return QPixmap(":/image/cards/RoadBuilder.jpg");
        default:
            return QPixmap();
    }

}
