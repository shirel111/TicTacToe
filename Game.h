#pragma once
#include "Board.h"

class Game 
{
private:
    Board board;

    int win_condition;

    bool checkDirection(int row, int col, const std::string& symbol, int dRow, int dCol) const;

    int countConsecutive(int row, int col, const std::string& symbol, int dRow, int dCol) const;

public:
    Game(int board_size, int win_condition);

    void playGame();

    Board& getBoard();

    bool checkWin(int row, int col, const std::string& symbol) const;
};