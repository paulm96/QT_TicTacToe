#include "tictactoe.h"
#include <QDebug>
#include <QSize>

TicTacToe::TicTacToe(QWidget *parent, int board_size, Figure _currentPlayer, int winningNumber, Player *player,
                     Computer *computer, bool status) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe),
    parent(parent),
    board_size(board_size),
    winningNumber(winningNumber),
    player(player),
    computer(computer),
    status(status)
{
    game = new Game(board_size, _currentPlayer, winningNumber, player, computer, status);
    ui->setupUi(this);

    for (auto i = 0; i < board_size; ++i){
        for(auto j = 0; j < board_size; ++j){
            board.push_back(new QPushButton);
            ui->gridLayout->addWidget(board.back(),i, j, Qt::AlignCenter);
            board.back()->setFixedSize(260/board_size, 260/board_size);
            connect(board.back(), SIGNAL(clicked()), this, SLOT(button_clicked()));
        }
    }
    connect(ui->change_button, SIGNAL(released()), this, SLOT(end_of_game_clicked()));

    ui->textEdit->setText("GAME LOG\nGame is created");

    if (_currentPlayer == computer->getFigure()){
        isPlayerMove = false;
    } else {
        isPlayerMove = true;
    }

   // connect(this, SIGNAL(sig()), this, SLOT(test()));
}

TicTacToe::~TicTacToe() {
    delete ui;
    qDebug() << "TicTacToe_destructor_done";
}

void TicTacToe::updateUI(){
    for( auto i = 0; i < board_size; ++i){
        for( auto j = 0; j < board_size; ++j){
            if(game->getBoard()->getBoard()[i][j] == (Figure) 0 )
                board[i*board_size + j]->setText("X");
            if(game->getBoard()->getBoard()[i][j] == (Figure) 1 )
                board[i*board_size + j]->setText("O");
        }
    }
}

void TicTacToe::end_of_game_clicked(){
    qDebug() << "end_of_game_clicked()";

    delete game;

    for(auto i:board)
        delete i;
    board.clear();

    this->close();
    parent->show();
}

void TicTacToe::button_clicked(){
    qDebug() << "button_clicked";
    QPushButton *button = (QPushButton *) sender();
    if(!status) return;

    if(isPlayerMove) {

        int i, j;
        for (auto k = 0; k<board_size*board_size; ++k){
            if(board[k] == button){
                i = k/board_size;
                j = (k%board_size);
                break;
            }
        }

        (game->getBoard()->getBoard())[i][j] = player->getFigure();
        ui->textEdit->append("player_move");
        updateUI();

        result(winningNumber, player->getFigure());

        isPlayerMove = false;

        //emit sig();

    }

        ui->textEdit->append("Computer is thinking...");
        coordinates = computer->move(game->getBoard(), winningNumber);
        ui->textEdit->append("computer_move");
        updateUI();

        result(winningNumber, computer->getFigure());

        isPlayerMove = true;
}

void TicTacToe::result(int winningNumber, Figure figure){
    if (game->getBoard()->ifSettled(winningNumber, figure)){
        if(isPlayerMove) ui->textEdit->append("player wins");
        else ui->textEdit->append("player loses");

        status = false;
        return;
    }
    if (game->getBoard()->ifFull()){
        ui->textEdit->append("draw");
        status = false;
        return;
    }
}

//void TicTacToe::test(){

//}
