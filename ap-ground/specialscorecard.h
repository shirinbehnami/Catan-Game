#ifndef SPECIALSCORECARD_H
#define SPECIALSCORECARD_H

#include "cards.h"

class SpecialScorecard : public cards
{
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        Knight,
        RoadBuilder
    };
    Q_ENUM(State)

    explicit SpecialScorecard(State state);
    virtual ~SpecialScorecard();

    State state() const { return m_state; }
    void setState(State State);

signals:

private:
    State m_state;
    int score;

    static QPixmap stateToPixmap(State state);

private slots:
    void updateHexagonal(State state);
};

#endif // SPECIALSCORECARD_H
