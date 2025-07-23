#include <stdio.h>

void draw_area(int leftP, int RightP, int ballX, int ballY, int first_score, int second_score,
               int player1);                    // фун-я отрисовки поля
int winner(int first_score, int second_score);  // фун-я определения победителя

int main() {
    const int height = 25, width = 80;
    int leftP = 12, rightP = 12;                     // начальные позиции правой и левой ракеток
    int ballX = 40, ballY = 12;                      // начальные позиции мяча
    int first_score = 20, second_score = 0;           // начальный счет
    int ball_direction_X = 1, ball_direction_Y = 1;  // направление движения мяча

    int player1 = 1, player2 = 0;

    int choose_player;
    printf("Введите номер игрока, который ходит первым (левый - 1 / правый - 2): ");
    if (scanf("%d", &choose_player) == 1) {
        if (choose_player == 2) {
            player1 = 0;
            player2 = 1;
            ball_direction_X = -1;
            ball_direction_Y = -1;
        }
    }

    draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
    while (1) {
        // printf("Введите шаг для игрока\n");
        char ch = getchar();

        // механизм движения вверх ракетки левого игрока
        if ((ch == 'A' || ch == 'a') && player1) {
            player1 = 0;
            player2 = 1;
            if (leftP == 2)  // не делаем движение вверх, если центр ракетки стоит на 2 строке
                leftP -= 0;  // перемещение в верхнюю строку

            else if (leftP == 3)  // делаем движение только на одну строку вверх, если
                                  // центр ракетки стоит на 3 строке
                leftP -= 1;       // перемещение на одну строку вверх

            else  // движение на 2 позиции вверх в обычных условиях
                leftP -= 2;
            draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
        }

        // механизм движения вниз ракетки левого игрока
        if ((ch == 'z' || ch == 'Z') && player1) {
            player1 = 0;
            player2 = 1;
            if (leftP == 22)  // перемещает ракетку вниз на 1 строку,если она находится
                              // на строке 23
                leftP += 1;
            else if (leftP == 23)  // не двигает ракетку, если она стоит на строке 24
                leftP += 0;
            else  // движение на 2 позиции вниз при нажатии команды если нет
                  // доп.условии
                leftP += 2;
            draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
        }

        // механизм движения ракетки вверх правого игрока
        if ((ch == 'k' || ch == 'K') && player2) {
            player1 = 1;
            player2 = 0;
            if (rightP == 2)
                leftP -= 0;
            else if (rightP == 3)
                leftP -= 1;
            else
                rightP -= 2;
            draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
        }

        // механизм движения ракетки вниз правого игрока
        if ((ch == 'm' || ch == 'M') && player2) {
            player1 = 1;
            player2 = 0;

            if (rightP == 22)  // перемещает правую ракетку вниз на 1 строку,если она
                               // находится на строке 23
                rightP += 1;
            else if (rightP == 23)  // не двигает ракетку, если она стоит на строке 24
                leftP += 0;
            else  // без доп условий
                rightP += 2;
            draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
        }

        if (ch == ' ') {
            if (player1 == 1) {
                player1 = 0;
                player2 = 1;
            } else {
                player1 = 1;
                player2 = 0;
            }
            draw_area(leftP, rightP, ballX, ballY, first_score, second_score, player1);
        }
        if (ch == 'q' || ch == 'Q') break;

        if (winner(first_score, second_score)) break;

        // обновляем позицию мячика после каждого хода
        ballX += ball_direction_X;
        ballY += ball_direction_Y;

        // проверяем на столкновение с правой/левой стеной и если шар столкнулся –
        // меняем направление на противоположное
        if (ballY <= 0 || ballY >= height - 1) ball_direction_Y = -ball_direction_Y;

        // механизм обработки столкновений с ракетками
        if (ballX == 1 && (ballY >= leftP - 1 && ballY <= leftP + 1))
            ball_direction_X = -ball_direction_X;  // отбиваем шар в правую сторону левой ракеткой
        else if (ballX == width - 2 && (ballY >= rightP - 1 && ballY <= rightP + 1))
            ball_direction_X = -ball_direction_X;  // отбиваем шар в левую сторону правой ракеткой

        // начисление очков
        if (ballX <= 0) {
            second_score += 1;
            ballX = width / 2;
            ballY = height / 2;
            ball_direction_X = 1;
            ball_direction_Y = 1;
        } else if (ballX >= width - 1) {
            first_score += 1;
            ballX = width / 2;
            ballY = height / 2;
            ball_direction_X = -1;
            ball_direction_Y = 1;
        }
    }
    return 0;
}

void draw_area(int leftP, int RightP, int ballX, int ballY, int first_score, int second_score,
               int player1) {
    const int height = 25, width = 80;  // определяем границы поля
    printf("\033[0d\033[2J");           // при каждом вызове функции очищаем экран /033
                                        // предупреждает, что след идет команда

    printf("Левый: %d || Правый: %d (чтобы закончить игру нажмите q или Q)\n", first_score,
           second_score);

    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            int flag = 0;  // флаг, определяющий, выводим пробел или определенный символ

            // отрисовываем левую границу
            if (x == 0 && y > 0 && y < height) {
                printf("|");
                flag = 1;
            }

            // отрисовка правой границы
            if (x == width && y > 0 && y < height) {
                printf("|");
                flag = 1;
            }

            // отрисовываем верхннюю и нижнюю границу
            if (y == 0 || y == height) {
                printf("-");
                flag = 1;
            }

            // отрисовываем центр
            if (x == 40 && y != 0 && y != height && (y != ballY || x != ballX)) {
                printf("|");
                flag = 1;
            }

            // ракетка левого игрока
            if ((x == 1 && y == leftP) || (x == 1 && y == leftP + 1) ||
                (x == 1 && y == leftP - 1)) {
                printf("|");
                flag = 1;
            }

            // ракетка правого игрока
            if ((x == 79 && y == RightP) || (x == 79 && y == RightP + 1) ||
                (x == 79 && y == RightP - 1)) {
                printf("|");
                flag = 1;
            }

            // рисую мяч
            if (x == ballX && y == ballY) {
                printf("O");
                flag = 1;
            }

            if (!flag) {
                printf(" ");
            }
        }
        printf("\n");
    }
    (player1 == 1) ? printf("Сейчас ходит ПЕРВЫЙ ИГРОК\n") : printf("Сейчас ходит ВТОРОЙ ИГРОК\n");
}

int winner(int first_score, int second_score) {
    if (first_score == 21) {
        printf("\033[0d\033[2J");
        printf(
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                           "
            "          Победил первый "
            "игрок! \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        return 1;
    }

    if (second_score == 21) {
        printf("\033[0d\033[2J");
        printf(
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                           "
            "           Победил второй "
            "игрок! \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        return 1;
    }

    return 0;
}
