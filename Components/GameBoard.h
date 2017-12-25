//
// Created by pawel on 18.12.17.
//

#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H

#include "Figure.h"

class GameBoard {
public:
    explicit GameBoard(int board_size);
    GameBoard();
    virtual ~GameBoard();

    int getBoard_size() const;
    Figure **getBoard();

    void displayBoard() const;
    bool ifFull() const;
    bool ifSettled(int winningNumber, Figure figure) const;
    double heuristicValue(Figure _figure, int winningNumber) const;
private:
    int board_size;
    Figure **board;
};


#endif //TICTACTOE_GAMEBOARD_H
