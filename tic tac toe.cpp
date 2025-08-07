#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
// Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    return 0; // No winner yet
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker;
    cin >> marker;

    currentPlayer = 1;
    currentMarker = marker;

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        winner = checkWin();

        if (winner != 0) {
            cout << "Player " << winner << " wins!\n";
            return;
        }

        switchPlayer();
    }

    cout << "It's a tie!\n";
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    game();
    return 0;
}

