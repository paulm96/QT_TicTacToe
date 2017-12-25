//

#include <iostream>
#include "GameBoard.h"

//
// Created by pawel on 18.12.17.
GameBoard::GameBoard() {

}

GameBoard::GameBoard(int board_size) : board_size(board_size) {
    board = new Figure* [board_size];
    for(auto i = 0; i<board_size; ++i){
        board[i] = new Figure [board_size];
    }

    for(auto i = 0; i<board_size; ++i){
        for(auto j = 0; j<board_size; ++j){
            board[i][j] = empty;
        }
    }
}

GameBoard::~GameBoard() {
    std::cout << "Call the GameBoard class destructor\n" ;
    for(auto i = 0; i < board_size; ++i){
        delete [] board[i];
    }
    delete [] board;
}

int GameBoard::getBoard_size() const {
    return board_size;
}

Figure **GameBoard::getBoard() {
    return board;
}

void GameBoard::displayBoard() const {
    for(auto i = 0; i<board_size; ++i){
        for(auto j = 0; j<board_size; ++j){
            if(0 == board[i][j])
                std::cout << 'x';
            if(1 == board[i][j])
                std::cout << 'o';
            if(2 == board[i][j])
                std::cout << '.';

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool GameBoard::ifSettled(int winningNumber, Figure figure) const {     //FUNCKJA SPRAWDZAJACA CZY JEST ZWYCIESTWO
    int lev = 0, vert = 0, aslu = 0, asld = 0;
    int memI, memJ;
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] == figure) lev++;            //sprawdzanie w poziomie
            else lev = 0;
            if (lev == winningNumber) return true;

            if (board[j][i] == figure) vert++;       //sprawdzanie w pionie
            else vert = 0;
            if (vert == winningNumber) return true;

            memI = i;
            memJ = j;
            while (true) {
                if (board[memI++][memJ++] == figure) asld++;   //sprawdzanie skosu, kierunek ^<
                else asld = 0;
                if (asld == winningNumber) return true;
                if (memI == board_size || memJ == board_size) break;
            }

            memI = i;
            memJ = j;
            while (true) {
                if (board[memI--][memJ++] == figure) aslu++;    //sprawdzanie skosu, kierunek >^
                else aslu = 0;
                if (aslu == winningNumber) return true;
                if (memI < 0 || memJ == board_size) break;
            }
            asld = aslu = 0;
        }
        lev = vert = 0;
    }
    return false;
}

bool GameBoard::ifFull() const {            //FUNKCJA SPRAWDZAJACE CZY PLANSZA JEST PELNA (REMIS)
    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
            if (board[i][j] == empty) return false;
    return true;
}

double GameBoard::heuristicValue(Figure _figure, int winningNumber) const {
    double sum = 0;
    int lev = 0, vert = 0, aslu = 0, asld = 0;
    int memI, memJ;

    auto **tmpBoard = new Figure* [board_size];
    for(auto i = 0; i<board_size; ++i){
        tmpBoard[i] = new Figure [board_size];
    }

    for(auto i = 0; i<board_size; ++i){
        for(auto j = 0; j<board_size; ++j){
            tmpBoard[i][j] = empty;
        }
    }

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            tmpBoard[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if(tmpBoard[i][j] == empty) tmpBoard[i][j] = _figure;
        }
    }

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (tmpBoard[i][j] == _figure) lev++;            //sprawdzanie w poziomie
            else lev = 0;
            if (lev == winningNumber) ++sum;

            if (tmpBoard[j][i] == _figure) vert++;       //sprawdzanie w pionie
            else vert = 0;
            if (vert == winningNumber) ++sum;

            memI = i;
            memJ = j;
            while (true) {
                if (tmpBoard[memI++][memJ++] == _figure) asld++;   //sprawdzanie skosu, kierunek ^<
                else asld = 0;
                if (asld == winningNumber) ++sum;
                if (memI == board_size || memJ == board_size) break;
            }

            memI = i;
            memJ = j;
            while (true) {
                if (tmpBoard[memI--][memJ++] == _figure) aslu++;    //sprawdzanie skosu, kierunek >^
                else aslu = 0;
                if (aslu == winningNumber) ++sum;
                if (memI < 0 || memJ == board_size) break;
            }
            asld = aslu = 0;
        }
        lev = vert = 0;
    }

    for(auto i = 0; i < board_size; ++i){
        delete [] tmpBoard[i];
    }
    delete [] tmpBoard;

    return sum/10;
}

