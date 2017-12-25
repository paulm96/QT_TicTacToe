//
// Created by pawel on 18.12.17.
//

#ifndef TICTACTOE_COMPUTER_H
#define TICTACTOE_COMPUTER_H

#include <utility>
#include "../Components/Figure.h"
#include "../Components/GameBoard.h"

class Computer {
public:
    void move(GameBoard *board, int winningNumber);
    explicit Computer(Figure figure);
    double MinMax(Figure _figure, GameBoard *board, int winningNumber);
    double alfaBeta(Figure _figure, GameBoard *board, int winningNumber, double alfa, double beta, double level);
    Computer();
    Figure getFigure() const;
    void setFigure(Figure _figure);
private:
    Figure figure;
};


#endif //TICTACTOE_COMPUTER_H
