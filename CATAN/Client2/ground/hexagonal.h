#ifndef HEXAGONAL_H
#define HEXAGONAL_H

#include<QPushButton>
#include <QObject>

class hexagonal:public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        desert,
        wheat,
        clay,
        ore,
        wood,
        sheep,
        water
    };
    Q_ENUM(State)

    explicit hexagonal(QWidget *parent = nullptr);
    virtual ~hexagonal();

    State state() const { return m_state; }
    void setState(State State);
    QString getState();

signals:
    void stateChanged(State State);

private:
    State m_state;

    static QPixmap stateToPixmap(State state);

private slots:
    void updateHexagonal(State state);
};

#endif // HEXAGONAL_H
