#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BOARD_SIZE 9
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'
void init_board(char board[]);
void print_board(char board[]);
bool is_winner(char board[], char player);
bool is_board_full(char board[]);
int minimax(char board[], int depth, bool is_maximizing);
int get_best_move(char board[]);
int get_player_move(char board[]);
void play_game();
int main() 
{
    srand(time(NULL));
    play_game();
    return 0;
}

void init_board(char board[]) 
{
    for (int i = 0; i < BOARD_SIZE; i++) 
	{
        board[i] = EMPTY;
    }
}
void print_board(char board[]) 
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) 
	{
        printf(" %c ", board[i]);
        if (i % 3 == 2) 
		{
            printf("\n");
            if (i < BOARD_SIZE - 1) 
			{
                printf("---+---+---\n");
            }
        } else 
		{
            printf("|");
        }
    }
    printf("\n");
}
bool is_winner(char board[], char player) {
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i+3] == player && board[i+6] == player) {
            return true;
        }
    }
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

bool is_board_full(char board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

int minimax(char board[], int depth, bool is_maximizing) {
    if (is_winner(board, AI)) {
        return 10 - depth;
    }
    if (is_winner(board, PLAYER)) {
        return depth - 10;
    }
    if (is_board_full(board)) {
        return 0;
    }

    if (is_maximizing) {
        int best_score = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i] == EMPTY) {
                board[i] = AI;
                int score = minimax(board, depth + 1, false);
                board[i] = EMPTY;
                if (score > best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER;
                int score = minimax(board, depth + 1, true);
                board[i] = EMPTY;
                if (score < best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    }
}

int get_best_move(char board[]) {
    int best_score = -1000;
    int best_move = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == EMPTY) {
            board[i] = AI;
            int score = minimax(board, 0, false);
            board[i] = EMPTY;
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

    return best_move;
}

int get_player_move(char board[]) {
    int move;
    while (1) {
        printf("Enter your move (0-8): ");
        if (scanf("%d", &move) == 1) {
            if (move >= 0 && move < BOARD_SIZE && board[move] == EMPTY) {
                return move;
            }
        }
        printf("Invalid move. Try again.\n");
        while (getchar() != '\n');
    }
}

void play_game() {
    char board[BOARD_SIZE];
    init_board(board);

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("You are X, and the AI is O.\n");
    printf("The board positions are numbered 0-8 as follows:\n");
    printf(" 0 | 1 | 2 \n---+---+---\n 3 | 4 | 5 \n---+---+---\n 6 | 7 | 8 \n");

    while (1) {
        print_board(board);

        int player_move = get_player_move(board);
        board[player_move] = PLAYER;

        if (is_winner(board, PLAYER)) {
            print_board(board);
            printf("You win!\n");
            break;
        }

        if (is_board_full(board)) {
            print_board(board);
            printf("It's a tie!\n");
            break;
        }

        printf("AI is thinking...\n");
        int ai_move = get_best_move(board);
        board[ai_move] = AI;
        printf("AI chose position %d\n", ai_move);

        if (is_winner(board, AI)) {
            print_board(board);
            printf("AI wins!\n");
            break;
        }

        if (is_board_full(board)) {
            print_board(board);
            printf("It's a tie!\n");
            break;
        }
    }
}

