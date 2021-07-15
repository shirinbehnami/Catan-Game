#ifndef HEXAGONAL_H
#define HEXAGONAL_H

#include<QPushButton>
#include <QObject>

class hexagonal:public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int row READ row WRITE setRow)
    Q_PROPERTY(int col READ col WRITE setCol)
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

    int row() const { return m_row; }
    void setRow(int row) { m_row = row; }

    int col() const { return m_col; }
    void setCol(int col) { m_col = col; }

    State state() const { return m_state; }
    void setState(State State);

signals:
    void stateChanged(State State);

private:
    int m_row, m_col;
    State m_state;

    static QPixmap stateToPixmap(State state);

private slots:
    void updateHexagonal(State state);
};

#endif // HEXAGONAL_H
