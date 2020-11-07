#include "grid.h"
#include <iostream>

Grid* Grid::instance_ = nullptr;

Grid::Grid(int width, int height):
    width_(width), height_(height)
{
    array_ = new Tile*[height_];
    for (int i = 0; i < height_; i++) {
        array_[i] = new Tile[width_];
    }
}


Grid::Grid(const Grid& other):
    width_(other.width_), height_(other.height_)
{
    array_ = new Tile*[height_];
    for (int i = 0; i < height_; i++) {
        array_[i] = new Tile[width_];
        std::copy(other.array_[i], other.array_[i]+other.width_, array_[i]);
    }
}

Grid::Grid(Grid&& other):
    width_(other.width_), height_(other.height_), array_(other.array_)
{
    other.array_ = nullptr;
}


Grid& Grid::operator=(const Grid& other)
{
    if (this != &other) {
        DeleteGrid();
        width_ = other.width_;
        height_ = other.height_;
        array_ = new Tile*[height_];
        for (int i = 0; i < height_; i++) {
            array_[i] = new Tile[width_];
            std::copy(other.array_[i], other.array_[i]+other.width_, array_[i]);
        }
    }
    return *this;
}


Grid& Grid::operator=(Grid&& other)
{
    if (this != &other) {
        std::swap(width_, other.width_);
        std::swap(height_, other.height_);
        std::swap(array_, other.array_);
    }
    return *this;
}


Grid::~Grid()
{
    DeleteGrid();
}


Grid* Grid::GetInstance()
{
    if (!instance_) {
        instance_ = new Grid(gridWidth, gridHeight);
    }
    return instance_;
}


void Grid::DeleteInstance()
{
    instance_ = nullptr;
}


void Grid::DeleteGrid()
{
    if (array_) {
        for (int i = 0; i < height_; i++) {
            delete[] array_[i];
        }
        delete[] array_;
        array_ = nullptr;
    }
}


int Grid::Width()
{
    return width_;
}


int Grid::Height()
{
    return height_;
}

Tile** Grid::Array()
{
    return array_;
}

Tile& Grid::Array(int y, int x)
{
    return array_[y][x];
}

Grid::Iterator Grid::begin()
{
    return Iterator(0, 0);
}

Grid::Iterator Grid::end()
{
    return Iterator(height_, 0);
}


Grid::Iterator::Iterator(int y, int x): x_(x), y_(y) {}

Tile& Grid::Iterator::operator*()
{
    return Grid::GetInstance()->Array(y_,x_);
}

Grid::Iterator& Grid::Iterator::operator++()
{
    if (x_ + 1 >= Grid::GetInstance()->Width()) {
        y_++;
        x_ = 0;
    } else {
        x_++;
    }

    return *this;
}

Grid::Iterator Grid::Iterator::operator++(int)
{
    Iterator tmp(*this);
    operator++();
    return tmp;
}

bool Grid::Iterator::operator==(const Iterator& other)
{
    return (this->x_ == other.x_ && this->y_ == other.y_);
}

bool Grid::Iterator::operator!=(const Iterator &other)
{
    return !(operator==(other));
}
