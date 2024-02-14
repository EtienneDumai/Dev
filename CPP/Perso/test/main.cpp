#include <iostream>
#include <vector>

// Function to print the tic-tac-toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (const auto& row : board) {
        if (row[0] == player && row[1] == player && row[2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to play the tic-tac-toe game
void playGame() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Print the board
        printBoard(board);

        // Get the player's move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;

        // Update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }

        // Check if the board is full (tie)
        bool isFull = true;
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') {
                    isFull = false;
                    break;
                }
            }
            if (!isFull) {
                break;
            }
        }
        if (isFull) {
            std::cout << "It's a tie!" << std::endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}
