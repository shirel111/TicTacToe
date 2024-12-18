#include "Game.h"
#include <iostream>

Game::Game(int board_size, int win_condition) : board(board_size), win_condition(win_condition) {}

// Checks if the player wins by verifying four possible directions from a specific cell.
bool Game::checkWin(int row, int col, const std::string& symbol) const 
{
    return checkDirection(row, col, symbol, 1, 0) || // Row
        checkDirection(row, col, symbol, 0, 1) || // Column
        checkDirection(row, col, symbol, 1, 1) || // Main diagonal
        checkDirection(row, col, symbol, 1, -1);  // Anti-diagonal
}

// Checks for a winning sequence in a specified direction and its opposite.
bool Game::checkDirection(int row, int col, const std::string& symbol, int row_direction, int col_direction) const 
{
    int count = 1;

    count += countConsecutive(row, col, symbol, row_direction, col_direction);

    count += countConsecutive(row, col, symbol, -row_direction, -col_direction);

    return count >= win_condition;
}

// Counts consecutive symbols in a single direction until interrupted.
int Game::countConsecutive(int row, int col, const std::string& symbol, int row_direction, int col_direction) const
{
    int count = 0;

    for (int i = 1; i < win_condition; i++)
    {
        int new_row = row + i * row_direction;

        int new_col = col + i * col_direction;

        if (new_row >= 0 && new_row < board.getSize() && new_col >= 0 && new_col < board.getSize() && board.getCell(new_row, new_col) == symbol)
        {
            count++;
        }
        else 
        {
            break;
        }
    }

    return count;
}

void Game::playGame() 
{
    std::string current_player = "X";

    bool game_won = false;

    while (board.getTotalMoves() < board.getSize() * board.getSize() && !game_won) 
    {
        board.printBoard();

        std::cout << "\nPlayer " << current_player << ", enter your move: ";

        int move;

        std::cin >> move;

        if (!board.isValidMove(move)) 
        {
            std::cout << "Invalid move. Try again.\n";

            continue;
        }

        int row = (move - 1) / board.getSize();

        int col = (move - 1) % board.getSize();

        board.updateBoard(move, current_player);

        if (checkWin(row, col, current_player))
        {
            board.printBoard();

            std::cout << "\nPlayer " << current_player << " wins!\n";

            game_won = true;

            break;
        }

        current_player = (current_player == "X") ? "O" : "X";
    }

    if (!game_won) 
    {
        board.printBoard();

        std::cout << "\nIt's a draw!\n";
    }
}

Board& Game::getBoard()
{
    return board;
}