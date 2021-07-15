#ifndef NODE_H
#define NODE_H

#include<QPushButton>
#include <QObject>

class node:public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int row READ row WRITE setRow)
    Q_PROPERTY(int col READ col WRITE setCol)
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        house,
        none,
        city
    };
    Q_ENUM(State)

    explicit node(QWidget *parent = nullptr);
    virtual ~node();

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
    void updatenode(State state);
    void ChangeColor();
};

#endif // NODEL_H
