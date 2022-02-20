#include <stdio.h>
#include <stdlib.h>

void restart(char board[9][9]) //подготовка поля к началу
{
    char figures[9] = "rnbqkbnr";
    int x = 0, y = 0, i = 0;
    for (y = 8; y >= 0; y--) { //столбец цифр

        (board[y][0]) = ((8 - y) + '0');
    }

    for (x = 1; x < 9; x++) { //строка букв
        (board[8][x]) = (x + 96);
    }

    for (y = 2; y < 6; y++) { //пустые клетки
        for (x = 1; x < 9; x++) {
            board[y][x] = 46;
        }
    }

    for (x = 1; x < 9; x++) { //пешки
        board[1][x] = 'p';
        board[6][x] = 'P';
    }

    for (i = 0; i < 8; i++) { //остальные фигуры
        board[0][i + 1] = figures[i];
        board[7][i + 1] = figures[i] - 32;
    }

    board[8][0] = ' '; //левый нижний угол
}

void conclusion(char board[9][9]) //вывод поля
{
    printf("\n");
    int x = 0, y = 0;
    for (y = 0; y < 9; y++) {
        for (x = 0; x < 9; x++) {
            printf("%c ", board[y][x]);
            if (x == 0) {
                printf(" ");
            }
        }
        printf("\n");
        if (y == 7) {
            printf("\n");
        }
    }
}

/*void repeat_move(char input[7])
{
    printf("Ошибка: Вы вышли за пределы поля\nПовторите ход:");
    scanf("%s", input);
    if (input[0] == 'K' || input[0] == 'Q' || input[0] == 'R' || input[0] == 'N'
        || input[0] == 'B') {
        move_check(input, 1);
    } else {
        move_check(input, 0);
    }
}*/

void move_check(char input[7], int move_format)
{
    int checker = 1;
    if (move_format == 1) {
        if ((8 - (input[2] - '0')) > 7 || (input[1] - 96) < 1
            || (8 - (input[2] - '0')) < 0 || (input[1] - 96) > 9
            || (8 - (input[5] - '0')) > 7 || (input[4] - 96) < 1
            || (8 - (input[5] - '0')) < 0 || (input[4] - 96) > 9) {
            checker = 0;
        } else {
            checker = 1;
        }
    } else {
        if ((8 - (input[1] - '0')) > 7 || (input[0] - 96) < 1
            || (8 - (input[1] - '0')) < 0 || (input[0] - 96) > 9
            || (8 - (input[4] - '0')) > 7 || (input[3] - 96) < 1
            || (8 - (input[4] - '0')) < 0 || (input[3] - 96) > 9) {
            checker = 0;
        } else {
            checker = 1;
        }
    }
    if (checker == 0) {
        printf("Ошибка: Вы вышли за пределы поля.\nПовторите ход: ");
        scanf("%s", input);
        if (input[0] == 'K' || input[0] == 'Q' || input[0] == 'R'
            || input[0] == 'N' || input[0] == 'B') {
            move_check(input, 1);
        } else {
            move_check(input, 0);
        }
    }
}

int main()
{
    system("clear");
    char board[9][9];
    int counter = 0;
    restart(board);
    conclusion(board);
    char input[7];

    printf("\nПервый ход белых (для выхода введите 'q'): ");
    scanf("%s", input);
    while (input[0] != 'q') {
        system("clear");
        printf("Последний ход: %s\n", input);
        if (input[0] == 'K' || input[0] == 'Q' || input[0] == 'R'
            || input[0] == 'N' || input[0] == 'B') {
            move_check(input, 1);
            if ((input[0] == board[(8 - (input[2] - '0'))][(input[1] - 96)])
                || ((input[0] + 32) //проверка на фигуру
                    == board[(8 - (input[2] - '0'))][(input[1] - 96)])) {
                board[(8 - (input[5] - '0'))][(input[4] - 96)]
                        = board[(8 - (input[2] - '0'))][(input[1] - 96)];
                board[(8 - (input[2] - '0'))][(input[1] - 96)] = '.';
            }
        } else {
            move_check(input, 0);
            board[(8 - (input[4] - '0'))][(input[3] - 96)]
                    = board[(8 - (input[1] - '0'))][(input[0] - 96)];
            board[(8 - (input[1] - '0'))][(input[0] - 96)] = '.';
        }
        conclusion(board);
        if (counter % 2 != 0) {
            printf("\nХод белых: ");
        } else {
            printf("\nХод черных: ");
        }
        counter++;
        scanf("%s", input);
    }

    return 0;
}