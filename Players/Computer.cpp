//
// Created by pawel on 18.12.17.
//

#include <iostream>
#include "Computer.h"

std::pair<int,int> Computer::move(GameBoard *board, int winningNumber) {
    std::pair<int,int> coordinates;
    std::cout << "\nZaczekaj na ruch przeciwnika...\n";
    double pre = -100, x;
    int moveX, moveY;  //startowa wartosc pre, moveX moveY do zapamietania wspolrzednych ruchu

    for (int i = 0; i < board->getBoard_size(); i++)
        for (int j = 0; j < board->getBoard_size(); j++)
            if ((board->getBoard())[i][j] == empty) {
                (board->getBoard())[i][j] = figure;
                //x = MinMax(figure, board, winningNumber);   //zbedne
                x = alfaBeta(figure, board, winningNumber, -100, +100, 19);  //size <5 level = 19, size==5 level=14, size > 5 level = 12
                std::cout << ".";    //"pasek ladowania ruchu"
                (board->getBoard())[i][j] = empty;
                if (x > pre) {   //jezeli zwracana przez minmax wartosc wieksza od poprzedniej to nadpisz
                    pre = x;
                    moveX = i;
                    moveY = j;
                }
            }
    std::cout << pre;
    (board->getBoard())[moveX][moveY] = figure;    //wykonaj ruch
    coordinates.first = moveX;
    coordinates.second = moveY;
    return coordinates;
}

Computer::Computer(Figure figure) : figure(figure) {}

void Computer::setFigure(Figure _figure) {
    figure = _figure;
}


Computer::Computer() {

}

Figure Computer::getFigure() const {
    return figure;
}

double Computer::MinMax(Figure _figure, GameBoard *board, int winningNumber) {     //ALGORYTM MINIMAX
    //return alfaBeta(_figure, board, winningNumber, -100, +100);
//    double pre, x;
//
//    if (board->ifSettled(winningNumber, _figure))
//        return (_figure == figure) ? winningNumber : -1 * winningNumber; //jezeli jest wygrana ktoregos z graczy to zwraca toWin lub -toWin
//    if (board->ifFull()) return 0;                                            //remis
//
//
//    _figure = (_figure == (Figure) 1) ? (Figure) 0 : (Figure) 1;              //wpisujemy przeciwna figure
//    pre = (_figure == figure) ? -10 : 10;                          //wartosc odniesienia, dla aiType niska bo szukamy max
//
//    for (int i = 0; i < board->getBoard_size(); i++)
//        for (int j = 0; j < board->getBoard_size(); j++)
//            if ((board->getBoard())[i][j] == empty) {
//                (board->getBoard())[i][j] = _figure;
//                x = MinMax(_figure, board, winningNumber);
//                (board->getBoard())[i][j] = empty;
//                if (((_figure == figure) && (x > pre)) || ((_figure != figure) && (x < pre))) pre = x;   //
//            }
//    return pre;   //zwraca najbardziej optymalna ze wzgledu na gracza ocene danego poziomu
}

double Computer::alfaBeta(Figure _figure, GameBoard *board, int winningNumber, double alfa, double beta, double level) {



    if (board->ifSettled(winningNumber, _figure))
        return (_figure == figure) ? winningNumber : -1 *
                                                     winningNumber; //jezeli jest wygrana ktoregos z graczy to zwraca toWin lub -toWin
    if (board->ifFull()) return 0;

    if(0 > level){
        Figure playerFigure = (_figure == (Figure) 1) ? (Figure) 0 : (Figure) 1;
        if(_figure == figure) {
            return (board->heuristicValue(playerFigure, winningNumber) - board->heuristicValue(_figure, winningNumber));
        }
        else{
            return (board->heuristicValue(_figure, winningNumber) - board->heuristicValue(playerFigure, winningNumber));
        }
    }

    _figure = (_figure == (Figure) 1) ? (Figure) 0 : (Figure) 1;

    if (_figure != figure) {
        for (auto i = 0; i < board->getBoard_size(); ++i) {
            for (auto j = 0; j < board->getBoard_size(); ++j) {
                if ((board->getBoard())[i][j] == empty) {
                    (board->getBoard())[i][j] = _figure;
                    beta = std::min(beta, alfaBeta(_figure, board, winningNumber, alfa, beta, --level));
                    (board->getBoard())[i][j] = empty;
                    if (alfa >= beta) break;
                }
            }
        }
        return beta;
    }
    if (_figure == figure) {
        for (auto i = 0; i < board->getBoard_size(); ++i) {
            for (auto j = 0; j < board->getBoard_size(); ++j) {
                if ((board->getBoard())[i][j] == empty) {
                    (board->getBoard())[i][j] = _figure;
                    alfa = std::max(alfa, alfaBeta(_figure, board, winningNumber, alfa, beta, --level));
                    (board->getBoard())[i][j] = empty;
                    if (alfa >= beta) break;
                }
            }
        }
        return alfa;
    }
}

