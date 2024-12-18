#include "Board.h"
#include <iostream>

Board::Board(int size) : board_size(size), total_moves(0) 
{
    grid.resize(size, std::vector<std::string>(size));

    int count = 1;

    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            grid[i][j] = std::to_string(count++);
        }
    }
}

void Board::printBoard() const 
{
    for (int i = 0; i < board_size; ++i) 
    {
        for (int j = 0; j < board_size; ++j) 
        {
            std::cout << grid[i][j] << "\t";
        }

        std::cout << "\n";
    }
}

bool Board::isValidMove(int move) const 
{
    if (move < 1 || move > board_size * board_size)
    {
        return false;
    }

    int row = (move - 1) / board_size;

    int col = (move - 1) % board_size;

    return grid[row][col] != "X" && grid[row][col] != "O";
}

void Board::updateBoard(int move, const std::string& symbol) 
{
    int row = (move - 1) / board_size;

    int col = (move - 1) % board_size;

    grid[row][col] = symbol;

    total_moves++;
}

std::string Board::getCell(int row, int col) const 
{
    return grid[row][col];
}

int Board::getSize() const 
{
    return board_size;
}

int Board::getTotalMoves() const 
{
    return total_moves;
}