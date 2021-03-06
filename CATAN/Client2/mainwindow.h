#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "ground/ground.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Player* P;
    game* G;

    int client_num;

    void number_of_player(); 
    void make_ground();
    void send_nonesense();
public slots:
    void connection();
    void send_number_of_player();

};
#endif // MAINWINDOW_H
