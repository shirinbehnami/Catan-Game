#ifndef TRADE_H
#define TRADE_H
#include <QPushButton>
#include <QMessageBox>
#include <ground/ground.h>
class trade:QObject
{
    Q_OBJECT
public:
    explicit trade(QObject *parent = nullptr);
    // virtual ~trade(){}
    void set(ground* g);

private:

    QPushButton* bank_trade;
    QPushButton* players_trade;
    int type_of_trade;
public slots:
    void show();
};

#endif // TRADE_H
