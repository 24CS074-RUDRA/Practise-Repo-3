#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

// Function to display the board
void showBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check for a winner
int checkWinner() {
    // Rows
    if (board[0] == board[1] && board[1] == board[2]) return 1;
    if (board[3] == board[4] && board[4] == board[5]) return 1;
    if (board[6] == board[7] && board[7] == board[8]) return 1;

    // Columns
    if (board[0] == board[3] && board[3] == board[6]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8]) return 1;
    if (board[2] == board[4] && board[4] == board[6]) return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return 0;
    }
    return 1;
}

void computerMove() {
    int move;
    srand(time(NULL));

    while (1) {
        if (board[move] != 'X' && board[move] != 'O') {
            board[move] = 'O';
            printf("Computer chose position %d\n", move + 1);
            break;
        }
    }
}
void playGame() {
    int position;

    while (1) {
        showBoard();
        printf("Your turn (X). Enter position (1-9): ");
        scanf("%d", &position);

        if (position < 1 || position > 9 || board[position - 1] == 'X' || board[position - 1] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[position - 1] = 'X';

        if (checkWinner()) {
            showBoard();
            printf("You win!\n");
            break;
        }

        if (isDraw()) {
            showBoard();
            printf("It's a draw!\n");
            break;
        }

        computerMove();

        if (checkWinner()) {
            showBoard();
            printf("Computer wins!\n");
            break;
        }

        if (isDraw()) {
            showBoard();
            printf("It's a draw!\n");
            break;
        }
    }
}

int main() {
    printf("=== TIC TAC TOE vs COMPUTER ===\n");
    printf("You are X. Computer is O.\n");
    playGame();
    return 0;
}

