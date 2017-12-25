#include "tictactoe.h"
#include <QDebug>
#include <QSize>

TicTacToe::TicTacToe(QWidget *parent, int board_size, Figure _currentPlayer, int winningNumber, Player *player,
                     Computer *computer, bool status) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe),
    parent(parent)
{
    game = new Game(board_size, _currentPlayer, winningNumber, player, computer, status);
    ui->setupUi(this);

    QSize obj = ui->gridLayout->sizeHint();
    for (auto i = 0; i < board_size; ++i){
        for(auto j = 0; j < board_size; ++j){
            board.push_back(new QPushButton);
            ui->gridLayout->addWidget(board.back(),i, j, Qt::AlignCenter);
            board.back()->setFixedSize(260/board_size, 260/board_size);
            connect(board.back(), SIGNAL(released()), this, SLOT(button_clicked()));
        }
    }
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(clicked()));

    qDebug() << computer->getFigure();
    if (_currentPlayer == computer->getFigure()){
        qDebug() << "done";
        computer->move(game->getBoard(), winningNumber);
        (board[4])->setText("O");
    }
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::clicked(){
    qDebug() << "clicked()";
    this->close();
    parent->show();
}

void TicTacToe::button_clicked(){
    qDebug() << "button_clicked";
    QPushButton *button = (QPushButton *) sender();
    if(button->text() == "")
        button->setText("X");

//    for (auto i = 0; i<board_size; ++i){   //tutaj nie rozpoznaje board_size wiec trzeba to ogarnac
//        if(board[i] == button)
//            ;//i tutaj - "(i%board_size)-1" - to jest board[][to], a "i/board_size" - to jest board[to][]
//    }

}

void TicTacToe::gameprocess(){
    qDebug() << "game_process";
}
