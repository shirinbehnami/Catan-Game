#ifndef ROAD_H
#define ROAD_H

#include<QPushButton>
#include <QObject>

class road:public QPushButton
{

    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)
public:
    enum State {
        thirty,
        ninety,
        thirtyNeg,
        none
    };
    Q_ENUM(State)

    explicit road(QWidget *parent = nullptr);
    virtual ~road();

    State state() const { return m_state; }
    void setState(State State);

signals:
    void stateChanged(State State);

private:
    State m_state;

    static QPixmap stateToPixmap(State state);

private slots:
    void updateroad(State state);
};

#endif // ROAD_H
