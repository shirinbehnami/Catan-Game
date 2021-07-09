#ifndef GROUND_H
#define GROUND_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ground; }
QT_END_NAMESPACE

class hexagonal;

class ground : public QMainWindow
{
    Q_OBJECT

public:
    ground(QWidget *parent = nullptr);
    ~ground();

    hexagonal* hexagonalAt(int row, int col) const;

    void makeground();

private:
    Ui::ground *ui;
    hexagonal* m_hexagonal[19];
};
#endif // GROUND_H
