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
    void updateUI();

    void result(int winningNumber, Figure figure);

signals:
   // void sig();


private:
    Ui::TicTacToe *ui;
    QWidget *parent;
    Player *player;
    Computer *computer;
    Game *game;

    std::pair<int,int> coordinates;

    QVector<QPushButton *> board;
    int board_size;
    int winningNumber;
    bool isPlayerMove;
    bool status;

private slots:
    void end_of_game_clicked();
    void button_clicked();
    void test();
};

#endif // TICTACTOE_H
