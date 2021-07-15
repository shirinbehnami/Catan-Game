#ifndef CARDS_H
#define CARDS_H

#include<QPushButton>
#include <QObject>

class cards:public QPushButton
{
public:
    explicit cards(QWidget *parent = nullptr);
    virtual ~cards();
};

#endif // CARDS_H
