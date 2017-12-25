//
// Created by pawel on 18.12.17.
//

#include <iostream>
#include "Player.h"
#include "../Components/GameBoard.h"

void Player::move(GameBoard *board, std::pair<int, int> coordinates) {
    std::cout << "\nPlayer coordinates are " << coordinates.first << " " << coordinates.second << std::endl;
    if ((board->getBoard())[coordinates.first][coordinates.second] == empty) {
        (board->getBoard())[coordinates.first][coordinates.second] = figure;
    }
    else {
        std::string exception = "\nPole jest juz zajęte!\n";
        throw exception;
    }
}

Player::Player(Figure figure) : figure(figure) {}

void Player::setFigure(Figure _figure) {
    figure = _figure;
}

Player::Player() {

}

Figure Player::getFigure() const {
    return figure;
}
