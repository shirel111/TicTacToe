#pragma once
#include <vector>
#include <string>

class Board 
{
private:
    int board_size;

    std::vector<std::vector<std::string>> grid;

    int total_moves;

public:
    Board(int size);

    void printBoard() const;

    bool isValidMove(int move) const;

    void updateBoard(int move, const std::string& symbol);

    std::string getCell(int row, int col) const;

    int getSize() const;

    int getTotalMoves() const;
};