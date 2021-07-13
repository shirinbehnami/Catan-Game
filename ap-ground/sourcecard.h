#ifndef SOURCECARD_H
#define SOURCECARD_H

#include "cards.h"

class SourceCard:public cards
{
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        wheat,
        clay,
        ore,
        wood,
        sheep
    };
    Q_ENUM(State)

    explicit SourceCard(State state);
    virtual ~SourceCard();

    State state() const { return m_state; }
    void setState(State State);

signals:
    void stateChanged(State State);

private:
    State m_state;

    static QPixmap stateToPixmap(State state);

private slots:
    void updatecard(State state);

};

#endif // SOURCECARD_H
