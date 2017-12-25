//
//
// Created by pawel on 18.12.17.

#include <iostream>
#include "Game.h"
#include "Players/Player.h"


Game::Game() {

}

Game::Game(int _board_size, Figure _currentPlayer, int _winningNumber, Player *player, Computer *computer, bool _status):
    board_size(_board_size),
    currentPlayer(_currentPlayer),
    winningNumber(_winningNumber),
    player(player),
    computer(computer),
    status(_status)
{
    board = new GameBoard(board_size);
}

void Game::settings(int _board_size, Figure _currentPlayer, int _winningNumber, bool _status) {
    board_size = _board_size;
    currentPlayer = _currentPlayer;
    winningNumber = _winningNumber;
    status = _status;

    board = new GameBoard(board_size);
}



double Game::boardEvaluation() const {
    return 0;
}


void Game::reset() {
    status = false;
    board_size = 0;
    delete board;

}

void Game::showBoard() const {
    board->displayBoard();
}

GameBoard* Game::getBoard(){
    return board;
}

void Game::gameProcess(Player *player, Computer *computer) {
    introduction(player, computer);

    std::pair<int, int> coordinates;

    for (;;) {
        if (player->getFigure() == currentPlayer) {
            std::cout << std::endl << "Podaj wspolrzedne Twojego ruchu: ";
            std::cin >> coordinates.first >> coordinates.second;
            try {
                player->move(board, coordinates);
            }
            catch (std::string &exception) {
                std::cout << exception;
                continue;
            }

            std::cout << "\033[2J\033[1;1H";   //clear the screen
            showBoard();

            if (board->ifSettled(winningNumber, currentPlayer)) {
                std::cout << "WYGRANA GRACZA";
                break;
            }

            if(board->ifFull()){
                std::cout << "REMIS";
                break;
            }
            currentPlayer = computer->getFigure();
        }

        if (computer->getFigure() == currentPlayer) {

            computer->move(board, winningNumber);
            getchar();
            getchar();
            std::cout << "\033[2J\033[1;1H";   //clear the screen
            showBoard();

            //std::cout << "\nHeuristic value: " << board->heuristicValue(computer->getFigure(), winningNumber) << std::endl;

            if (board->ifSettled(winningNumber, currentPlayer)) {
                std::cout << "WYGRANA KOMPUTERA";
                break;
            }
            if(board->ifFull()){
                std::cout << "REMIS";
                break;
            }
            currentPlayer = player->getFigure();
        }
    }


}

void Game::introduction(Player *player, Computer *computer) {
    int _figure;
    int _board_size;
    int _winningNumber;

    std::cout << "Witaj w grze kółko i krzyżyk, wybierz ustawienia:\n"
            "Jaka wybierasz figure? (0=x lub 1=o) ";
    std::cin >> _figure;
    player->setFigure((Figure) _figure);

    _figure = (1 == _figure)? (Figure) 0 : (Figure) 1;
//    if (0 == _figure) _figure = 1;
//    if (1 == _figure) _figure = 0;
    computer->setFigure((Figure) _figure);
    std::cout << (int) computer->getFigure();

    std::cout << std::endl << "Kto ma zaczac? (0=x lub 1=o) ";
    std::cin >> _figure;

    std::cout << std::endl << "Jaki rozmiar planszy? ";
    std::cin >> _board_size;

    std::cout << std::endl << "Ile w rzedzie wygrywa? ";
    std::cin >> _winningNumber;

    settings(_board_size, (Figure) _figure, _winningNumber);
}

