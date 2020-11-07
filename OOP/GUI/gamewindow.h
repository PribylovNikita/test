#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "Game/game.h"
#include "Game/levels.h"
#include "Grid/grid.h"

#define TILE_SIZE 50
#define OBJECT_SIZE 40

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void UpdateView();
    void keyPressEvent(QKeyEvent* event);
private:
    Ui::GameWindow *ui;
    QGraphicsScene* scene;
    QGraphicsView* view;
    Game game;
    //QGraphicsEllipseItem* playerTexture;
};
#endif // GAMEWINDOW_H
