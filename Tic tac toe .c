#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char player = 'X';
char ai = 'O';

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        if (i < 2) {
            printf("---------\n");
        }
    }
}

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

void aiMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = ai;
}

int main() {
    srand(time(NULL));
    resetBoard();
    printBoard();
    while (1) {
        int row, col;
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input. Please enter a number between 0 and 2.\n");
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Cell is already occupied. Please choose another cell.\n");
            continue;
        }
        board[row][col] = player;
        printBoard();
        if (checkWin(player)) {
            printf("You win!\n");
            break;
        }
        aiMove();
        printBoard();
        if (checkWin(ai)) {
            printf("AI wins!\n");
            break;
        }
    }
    return 0;
}