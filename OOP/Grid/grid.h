#ifndef GRID_H
#define GRID_H

#include <algorithm>
#include <memory>
#include "Grid/tile.h"

const int gridWidth = 10;
const int gridHeight = 10;

using GridP = std::unique_ptr<class Grid>;

class Grid
{
public:
    class Iterator;

    static Grid* GetInstance();
    int Width();
    int Height();
    Tile** Array();
    Tile& Array(int x, int y);

    Iterator begin();
    Iterator end();

protected:
    static void DeleteInstance();

private:
    Grid(int width, int height);
    Grid(const Grid& other);
    Grid(Grid&& other);
    ~Grid();
    Grid& operator=(const Grid& other);
    Grid& operator=(Grid&& other);
    void DeleteGrid();

    static Grid* instance_;
    int width_;
    int height_;
    Tile** array_;

};

class Grid::Iterator
{
public:
    Iterator(int y, int x);
    Tile& operator*();
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);
private:
    int x_, y_;
};

#endif // GRID_H
