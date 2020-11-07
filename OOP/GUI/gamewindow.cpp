#include "GUI/gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    setCentralWidget(view);
    setStyleSheet("background-color: lightGray;");

    game.StartLevel();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::UpdateView()
{
    scene->clear();
    PlayerP player = game.Level().GetPlayer();
    Grid* grid = Grid::GetInstance();
    for (int i = 0; i < grid->Height(); i++) {
        for (int j = 0; j < grid->Width(); j++) {
            switch (grid->Array()[i][j].Type()) {
            case TileType::Wall:
                scene->addRect(TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE, QPen(Qt::SolidLine), QBrush(Qt::DiagCrossPattern));
                break;
            case TileType::Pass:
                scene->addRect(TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE, QPen(Qt::SolidLine), QBrush(Qt::white));
                break;
            case TileType::Start:
                scene->addRect(TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE, QPen(Qt::SolidLine), QBrush(Qt::blue));
                break;
            case TileType::Exit:
                scene->addRect(TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE, QPen(Qt::SolidLine), QBrush(Qt::green));
                break;
            case TileType::Door:
                scene->addRect(TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE, QPen(Qt::SolidLine), QBrush(Qt::cyan));
                break;
            }
            AbstractItemP tmp = grid->Array(i,j).Item();
            if (tmp) {
                if (tmp->WhatIsIt() == typeid(Artifact)) {
                    scene->addEllipse(TILE_SIZE*j+(TILE_SIZE-OBJECT_SIZE)/2, TILE_SIZE*i+(TILE_SIZE-OBJECT_SIZE)/2, OBJECT_SIZE, OBJECT_SIZE, QPen(Qt::SolidLine), QBrush(Qt::darkRed));
                } else if (tmp->WhatIsIt() == typeid(Key)) {
                    scene->addEllipse(TILE_SIZE*j+(TILE_SIZE-OBJECT_SIZE)/2, TILE_SIZE*i+(TILE_SIZE-OBJECT_SIZE)/2, OBJECT_SIZE, OBJECT_SIZE, QPen(Qt::SolidLine), QBrush(Qt::darkYellow));
                } else if (tmp->WhatIsIt() == typeid(Life)) {
                    scene->addEllipse(TILE_SIZE*j+(TILE_SIZE-OBJECT_SIZE)/2, TILE_SIZE*i+(TILE_SIZE-OBJECT_SIZE)/2, OBJECT_SIZE, OBJECT_SIZE, QPen(Qt::SolidLine), QBrush(Qt::darkGreen));
                }
            }
        }
    }
    scene->addEllipse(player->X()*TILE_SIZE+(TILE_SIZE-OBJECT_SIZE)/2, player->Y()*TILE_SIZE+(TILE_SIZE-OBJECT_SIZE)/2, OBJECT_SIZE, OBJECT_SIZE, QPen(Qt::SolidLine), QBrush(Qt::black));
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()) {
    case Qt::Key_W:
        game.MovePlayer(Direction::up);
        break;
    case Qt::Key_A:
        game.MovePlayer(Direction::left);
        break;
    case Qt::Key_S:
        game.MovePlayer(Direction::down);
        break;
    case Qt::Key_D:
        game.MovePlayer(Direction::right);
        break;
    default:
        break;
    }

    UpdateView();
}
