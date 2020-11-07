#include "Objects/player.h"

Player::Player(int x, int y):
    x_(x), y_(y), lives_(playerStartingLives), artifacts_(0), keys_(0)
{

}

void Player::Move(Direction dir)
{
    switch (dir) {
    case Direction::up:
        y_--;
        break;
    case Direction::left:
        x_--;
        break;
    case Direction::down:
        y_++;
        break;
    case Direction::right:
        x_++;
        break;
    default:
        break;
    }
}

int Player::X() const
{
    return x_;
}

int Player::Y() const
{
    return y_;
}

int Player::Lives() const
{
    return lives_;
}

int Player::Artifacts() const
{
    return artifacts_;
}

int Player::Keys() const
{
    return keys_;
}

void Player::operator+=(AbstractItem& item)
{
    item.Interact(*this);
}

bool Player::Heal()
{
    if (lives_ == playerMaxLives) {
        return false;
    }
    lives_++;
    return true;
}

void Player::LoseLife()
{
    lives_--;
}

void Player::TakeArtifact()
{
    artifacts_++;
}

void Player::TakeKey()
{
    keys_++;
}

bool Player::OpenDoor()
{
    if (keys_ > 0) {
        keys_--;
        return true;
    }
    return false;
}
