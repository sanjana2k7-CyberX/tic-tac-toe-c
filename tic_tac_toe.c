#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char board[3][3];
void initBoard() {
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
board[i][j] = ' ';
}
void printBoard() {
printf("\n");
for (int i = 0; i < 3; i++) {
printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
if (i < 2) printf("\n---+---+---\n");
}
printf("\n");
}
int checkWin() {
for (int i = 0; i < 3; i++)
if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
board[i][0] != ' ')
return 1;
for (int i = 0; i < 3; i++)
if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
board[0][i] != ' ')
return 1;
if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
board[0][0] != ' ')
return 1;
if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
board[0][2] != ' ')
return 1;
return 0;
}
int checkDraw() {
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
if (board[i][j] == ' ')
return 0;
return 1;
}
void computerMove(char s) {
int c, r, col;
while (1) {
c = rand() % 9 + 1;
r = (c - 1) / 3;
col = (c - 1) % 3;
if (board[r][col] == ' ') {
board[r][col] = s;
printf("Computer chose %d\n", c);
break;
}
}
}
int main() {
int choice, row, col;
char player, comp, turn;
srand(time(0));
initBoard();
printf("\nTIC TAC TOE\n");
printf("---------------------------\n");
printf("Rules:\n");
printf("1. Choose your symbol X or O.\n");
printf("2. Enter numbers 1-9 to place your mark.\n");
printf("3. Positions:\n\n");
printf(" 1 | 2 | 3 \n");
printf("---+---+---\n");
printf(" 4 | 5 | 6 \n");
printf("---+---+---\n");
printf(" 7 | 8 | 9 \n\n");
while (1) {
printf("Choose X or O: ");
scanf(" %c", &player);
if (player == 'X' || player == 'O' || player == 'x' || player == 'o')
break;
printf("Invalid choice, try again.\n");
}
if (player == 'x' || player == 'X') {
player = 'X';
comp = 'O';
} else {
player = 'O';
comp = 'X';
}
turn = player;
while (1) {
printBoard();
if (turn == player) {
printf("Your turn (%c). Enter position (1-9): ", player);
scanf("%d", &choice);
if (choice < 1 || choice > 9) {
printf("Invalid position.\n");
continue;
}
row = (choice - 1) / 3;
col = (choice - 1) % 3;
if (board[row][col] != ' ') {
printf("Position already taken.\n");
continue;
}
board[row][col] = player;
} else {
computerMove(comp);
}
if (checkWin()) {
printBoard();
if (turn == player)
printf("You win!\n");
else
printf("Computer wins!\n");
break;
}
if (checkDraw()) {
printBoard();
printf("It's a draw.\n");
break;
}
turn = (turn == player) ? comp : player;
}
return 0;
}
