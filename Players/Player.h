//
// Created by pawel on 18.12.17.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <utility>
#include "../Components/Figure.h"
#include "../Components/GameBoard.h"

class Player {
public:

    void move(GameBoard *board, std::pair<int, int> coordinates);

    explicit Player(Figure figure);

    Player();

    Figure getFigure() const;

    void setFigure(Figure _figure);

private:
    Figure figure;
};


#endif //TICTACTOE_PLAYER_H
