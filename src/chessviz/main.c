#include </home/nothomepc/prog/Ztest/chessviz.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[9][9]
            = {"8rnbqkbnr",
               "7pppppppp",
               "6........",
               "5........",
               "4........",
               "3........",
               "2PPPPPPPP",
               "1RNBQKBNR",
               " abcdefgh"};
    char input[7];

    system("clear");
    conclusion(board);
    printf("\nПервый ход белых (для выхода введите 'q'): ");
    scanf("%s", input);
    while (input[0] != 'q') {
        input[0] = move(input, board);
    }
    return 0;
}