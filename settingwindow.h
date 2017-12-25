#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include "tictactoe.h"
#include "ui_settingwindow.h"
#include "Players/Player.h"
#include "Players/Computer.h"
#include "Components/Figure.h"
#include "Game.h"

namespace Ui {
class settingWindow;
}

class settingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = 0);
    ~settingWindow();

    Player *player;
    Computer *computer;
    int board_size = 3;
    int winningNumber = 2;
    Figure currentPlayer;
private:
    Ui::settingWindow *ui;
    TicTacToe *tictactoe;

private slots:
    void start_pressed();
    void buttonGroup_1_pressed(QAbstractButton *button);
    void buttonGroup_2_pressed(QAbstractButton *button);
    void spinBox_size_choosen(int);
    void spinBox_win_choosen(int);
};

#endif // SETTINGWINDOW_H
