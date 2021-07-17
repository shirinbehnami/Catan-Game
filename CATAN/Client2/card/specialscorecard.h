#ifndef SPECIALSCORECARD_H
#define SPECIALSCORECARD_H

#include <QMap>

#include "card.h"

class SpecialScoreCard : public cards
{
    Q_OBJECT

public:
    enum State {
        LargestArmy,
        RoadBuilder
    };
    Q_ENUM(State)

    explicit SpecialScoreCard(State state,QWidget *parent = nullptr);
    virtual ~SpecialScoreCard();

    State state() const { return m_state; }
    QString get_state();


    static QMap<QString,int> Cardholder;
signals:

private:

    const State m_state;
    int score;

    QPixmap stateToPixmap(State state);

private slots:
};



#endif // SPECIALSCORECARD_H
