#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include "ui_tictactoe.h"
#include "Game.h"
#include <QVector>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent, int board_size, Figure _currentPlayer, int winningNumber, Player * player,
                       Computer *computer, bool status = true);
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;
    QWidget *parent;
    Player *player;
    Computer *computer;
    Game *game;
    QPushButton *button;
    QVector<QPushButton *> board;

    void gameprocess();

private slots:
    void clicked();
    void button_clicked();
};

#endif // TICTACTOE_H
