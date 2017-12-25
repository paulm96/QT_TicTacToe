//
// Created by pawel on 18.12.17.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Components/GameBoard.h"
#include "Components/Result.h"
#include "Players/Player.h"
#include "Players/Computer.h"

class Game {
public:
    Game();
    Game(int board_size, Figure _currentPlayer, int _winningNumber, Player *player,
         Computer *computer, bool _status = true);
    void gameProcess(Player *player, Computer *computer);
    GameBoard* getBoard();
private:
    bool status;
    int board_size;
    int winningNumber;
    GameBoard *board;
    Figure currentPlayer;
    Result result;
    Player *player;
    Computer *computer;

    void introduction(Player *player, Computer *computer);
    void settings(int _board_size, Figure _currentPlayer, int _winningNumber, bool _status = true);
    double boardEvaluation() const;
    void showBoard() const;
    void reset();

    bool ifSettled() const;
    bool ifFull() const;

};


#endif //TICTACTOE_GAME_H
