#include <stdio.h>
#include <stdlib.h>

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

//функция позоляющая изменить (исправить) ход (ошибку в ходе)
int repeat(int status, char input[7])
{
    system("clear");
    if (status == 1) {
        printf("Ошибка: ");
        printf("Вы вышли за пределы поля.");
    } else if (status == 2) {
        printf("Ошибка: ");
        printf("Фигура не соответствует фaктической.");
    } else if (status == 3) {
        printf("Ошибка: ");
        printf("Тип хода не соответствует фактическому.");
    }
    if (status != 0) {
        printf("\nПовторите ход: ");
        scanf("%s", input);
    }
    return (status);
}

//функция проверок хода
void move_check(char input[7], char board[9][9])
{
    int checker = 999, status, move_format;

    while (checker != 0) {
        checker = 0;

        if (input[0] == 'K' || input[0] == 'Q' || input[0] == 'R'
            || input[0] == 'N' || input[0] == 'B') {
            move_format = 1;
        } else {
            move_format = 0;
        }

        //проверка на выход за пределы поля
        if (move_format == 1) {
            if ((8 - (input[2] - '0')) > 7 || (input[1] - 96) < 1
                || (8 - (input[2] - '0')) < 0 || (input[1] - 96) > 9
                || (8 - (input[5] - '0')) > 7 || (input[4] - 96) < 1
                || (8 - (input[5] - '0')) < 0 || (input[4] - 96) > 9) {
                status = 1;
            }
        } else {
            if ((8 - (input[1] - '0')) > 7 || (input[0] - 96) < 1
                || (8 - (input[1] - '0')) < 0 || (input[0] - 96) > 9
                || (8 - (input[4] - '0')) > 7 || (input[3] - 96) < 1
                || (8 - (input[4] - '0')) < 0 || (input[3] - 96) > 9) {
                status = 1;
            }
        }

        //проверка на соответствие фигур
        if (move_format == 1) {
            if ((input[0] != board[(8 - (input[2] - '0'))][(input[1] - 96)])
                || ((input[0] + 32)
                    != board[(8 - (input[2] - '0'))][(input[1] - 96)])) {
                status = 2;
            }
        }

        //проверки на соответствие хода
        //взятие
        if (move_format == 1) {
            if ((input[3] == 'x')
                && (board[(8 - (input[5] - '0'))][(input[4] - 96)] == '.')) {
                status = 3;
            }
        } else {
            if ((input[2] == 'x')
                && (board[(8 - (input[4] - '0'))][(input[3] - 96)] == '.')) {
                status = 3;
            }
        }

        //тихий ход
        if (move_format == 1) {
            if ((input[3] == '-')
                && (board[(8 - (input[5] - '0'))][(input[4] - 96)] != '.')) {
                status = 3;
            }
        } else {
            if ((input[2] == '-')
                && (board[(8 - (input[4] - '0'))][(input[3] - 96)] != '.')) {
                status = 3;
            }
        }

        if (checker != 0) {
            checker = repeat(status, input);
        }
        status = 0;
    }
}

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
    int counter = 0;
    char input[7];

    system("clear");
    conclusion(board);
    printf("\nПервый ход белых (для выхода введите 'q'): ");
    scanf("%s", input);
    while (input[0] != 'q') {
        move_check(input, board);
        system("clear");
        printf("Последний ход: %s\n", input);
        if (input[0] == 'K' || input[0] == 'Q' || input[0] == 'R'
            || input[0] == 'N' || input[0] == 'B') {
            board[(8 - (input[5] - '0'))][(input[4] - 96)]
                    = board[(8 - (input[2] - '0'))][(input[1] - 96)];
            board[(8 - (input[2] - '0'))][(input[1] - 96)] = '.';
        } else {
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