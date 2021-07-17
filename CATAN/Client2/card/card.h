#ifndef CARDS_H
#define CARDS_H

#include<QPushButton>
#include <QObject>

class cards:public QPushButton
{
public:
    enum State {};

    Q_ENUM(State)

    explicit cards(QWidget *parent = nullptr);
    virtual ~cards();

    virtual QString get_state()=0;

};

#endif // CARDS_H
