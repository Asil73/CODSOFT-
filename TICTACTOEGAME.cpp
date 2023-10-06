#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        std::cout << "Current Board:" << std::endl;
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
                gameOver = true;
            } else {
                bool isDraw = true;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (board[i][j] == ' ') {
                            isDraw = false;
                            break;
                        }
                    }
                }
                if (isDraw) {
                    std::cout << "The game is a draw!" << std::endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        } else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }
    }

    return 0;
}

