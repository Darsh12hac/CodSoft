#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Main diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))   // Anti-diagonal
        return true;

    return false;
}

// Function to check if the board is full, resulting in a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // If any cell is empty, game is not a draw
        }
    }
    return true; // If no empty cell found, it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X'; // Player X starts the game

    while (true) {
        // Print the board
        cout << "Current board:" << endl;
        printBoard(board);

        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        // Update the board with the player's move
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move! Cell already occupied. Try again." << endl;
            continue;
        }

        // Check for win
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}