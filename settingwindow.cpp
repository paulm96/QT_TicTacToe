#include "settingwindow.h"
#include <QDebug>

settingWindow::settingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settingWindow)
{
    player = new Player;
    player->setFigure((Figure) 0);
    computer = new Computer;
    computer->setFigure((Figure) 1);

    ui->setupUi(this);

    connect(ui->start_button, SIGNAL(released()), this, SLOT(start_pressed()));
    connect(ui->buttonGroup_1, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonGroup_1_pressed(QAbstractButton *)));
    connect(ui->buttonGroup_2, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonGroup_2_pressed(QAbstractButton *)));

    connect(ui->spinBox_size, SIGNAL(valueChanged(int)), this, SLOT(spinBox_size_choosen(int)));
    connect(ui->spinBox_win, SIGNAL(valueChanged(int)), this, SLOT(spinBox_win_choosen(int)));
}

settingWindow::~settingWindow()
{
    delete ui;
}

void settingWindow::spinBox_size_choosen(int _size){
    qDebug() << "spinBox_size_choosen" << _size ;
    board_size = _size;
}

void settingWindow::spinBox_win_choosen(int _winningNumber){
    qDebug() << "spinBox_win_choosen" << _winningNumber;
    winningNumber = _winningNumber;
}

void settingWindow::start_pressed(){
    qDebug() << "start_pressed";
    this->hide();
    tictactoe = new TicTacToe(this, board_size, currentPlayer, winningNumber, player, computer);
    tictactoe->show();
}

void settingWindow::buttonGroup_1_pressed(QAbstractButton *button){
    qDebug() << "buttonGroup_1_pressed";

    if (button->text() == "X"){
        player->setFigure((Figure) 0);
        computer->setFigure((Figure) 1);
    } else {
        player->setFigure((Figure) 1);
        computer->setFigure((Figure) 0);
    }
}

void settingWindow::buttonGroup_2_pressed(QAbstractButton *button){
    qDebug() << "buttonGroup_2_pressed";

    if (button->text() == "X"){
        currentPlayer = (Figure) 0;
    } else {
        currentPlayer = (Figure) 1;
    }
}


