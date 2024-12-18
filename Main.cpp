#include "Game.h"
#include <iostream>
#include <stdexcept>
#define CI_MODE

int main()
{
    try 
    {
        Game game(4, 4);

        bool gameWon = false;

        std::string currentPlayer = "X";

        for (int i = 0; i < 16; i++) 
        {
            game.getBoard().printBoard();

            int move;

            #ifndef CI_MODE

               std::cout << "Player " << currentPlayer << ", enter your move (1-16): ";
               
               std::cin >> move;

            #else

               move = (i % 16) + 1;
               
               std::cout << "CI Player " << currentPlayer << " move: " << move << std::endl;
            
            #endif

            // Validate the move
            if (move < 1 || move > game.getBoard().getSize() * game.getBoard().getSize()) 
            {
                std::cout << "Move out of bounds. Please try again." << std::endl;

                i--;

                continue;
            }

            if (!game.getBoard().isValidMove(move)) 
            {
                std::cout << "Invalid move. Cell already taken. Please try again." << std::endl;

                i--;

                continue;
            }

            // Make the move
            game.getBoard().updateBoard(move, currentPlayer);

            // Check for a win
            int row = (move - 1) / game.getBoard().getSize();

            int col = (move - 1) % game.getBoard().getSize();

            if (game.checkWin(row, col, currentPlayer))
            {
                game.getBoard().printBoard();

                std::cout << "Player " << currentPlayer << " wins the game!" << std::endl;

                gameWon = true;

                break;
            }

            currentPlayer = (currentPlayer == "X") ? "O" : "X";
        }

        if (!gameWon) 
        {
            game.getBoard().printBoard();

            std::cout << "The game ends in a draw." << std::endl;
        }

        return 0;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;

        return 1;
    }
    catch (...) 
    {
        std::cerr << "Unknown error occurred." << std::endl;

        return 2;
    }
}
