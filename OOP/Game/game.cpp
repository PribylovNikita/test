#include "Game/game.h"

Game::Game()
{

}

Levels& Game::Level()
{
    return level_;
}

void Game::StartLevel()
{
    level_.CreateDefaultLevel1();
}

bool Game::MovePlayer(Direction dir)
{
    int y = level_.GetPlayer()->Y();
    int x = level_.GetPlayer()->X();
    switch (dir) {
    case Direction::up:
        if (!PlayerAbleToMove(y-1, x)) {
            return false;
        }
        break;
    case Direction::left:
        if (!PlayerAbleToMove(y, x-1)) {
            return false;
        }
        break;
    case Direction::down:
        if (!PlayerAbleToMove(y+1, x)) {
            return false;
        }
        break;
    case Direction::right:
        if (!PlayerAbleToMove(y, x+1)) {
            return false;
        }
        break;
    }
    level_.GetPlayer()->Move(dir);

    y = level_.GetPlayer()->Y();
    x = level_.GetPlayer()->X();

    if (Grid::GetInstance()->Array(y,x).Item()) {
        *level_.GetPlayer() += *Grid::GetInstance()->Array(y,x).Item();
        Grid::GetInstance()->Array(y,x).SetItem(nullptr);
    }
    return true;
}

bool Game::PlayerAbleToMove(int y, int x)
{
    if (y < 0 || y > Grid::GetInstance()->Height()-1 || x < 0 || x > Grid::GetInstance()->Width()-1 ||
        Grid::GetInstance()->Array(y,x).Type() == TileType::Wall ||
       (Grid::GetInstance()->Array(y,x).Type() == TileType::Door && level_.GetPlayer()->Keys() == 0))
        return false;
    return true;
}
