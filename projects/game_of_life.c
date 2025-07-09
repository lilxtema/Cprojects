#include <ncurses.h>
#include <stdio.h>

#define INITIAL_DELAY 100
#define WIDTH 80
#define HEIGHT 25
#define MIN_SPEED 600
#define MAX_SPEED 50

void read_matrix(int matrix[HEIGHT][WIDTH]);
void output_matrix(int matrix[HEIGHT][WIDTH]);
void start_ncurses();
int count_cell(int matrix[HEIGHT][WIDTH], int i, int j);
void update_matrix(int matrix[HEIGHT][WIDTH]);
void user_speed(int *speed);

int main() {
    int matrix[HEIGHT][WIDTH];
    int speed = 300;
    read_matrix(matrix);
    if (!freopen("/dev/tty", "r", stdin))
        printf("n/a");  // перенаправляем в stdin из потока ввода из файла
    else {
        start_ncurses();
        output_matrix(matrix);
        erase();  // стираем экран
        refresh();

        while (1) {
            output_matrix(matrix);
            update_matrix(matrix);
            user_speed(&speed);
            if (speed == -1)
                break;
            else
                napms(speed);
        }
        endwin();
    }
    return 0;
}

void read_matrix(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH;) {
            int ch = getchar();
            if (ch == EOF) {
                break;
            } else if (ch == '0') {
                matrix[i][j] = 0;
                j++;
            }

            else if (ch == '1') {
                matrix[i][j] = 1;
                j++;
            }
        }
    }
}

void output_matrix(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mvaddch(i, j, matrix[i][j] ? '#' : ' ');
        }
    }
    printw("\n");
    printw("A/a: speed++        Z/z: speed--        Exit: Space");
    refresh();
}

void start_ncurses() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);  // делаем безблокирующий ввод
    curs_set(0);
}

int count_cell(int matrix[HEIGHT][WIDTH], int i, int j) {
    int count = 0;

    // подсчет соседей клетки по их координатам
    for (int i_coordinate = -1; i_coordinate <= 1; i_coordinate++) {
        for (int j_coordinate = -1; j_coordinate <= 1; j_coordinate++) {
            // исключаем из подсчета клетку, соседей которой считаем
            if (!(i_coordinate == 0 && j_coordinate == 0)) {
                int i_neighbour_coordinate =
                    (i + i_coordinate + HEIGHT) % HEIGHT;  // реализую зацикливание
                int j_neighbour_coordinate = (j + j_coordinate + WIDTH) % WIDTH;

                if (matrix[i_neighbour_coordinate][j_neighbour_coordinate]) count++;
            }
        }
    }

    return count;
}

void update_matrix(int matrix[HEIGHT][WIDTH]) {
    int result_matrix[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbours = count_cell(matrix, i, j);

            if (matrix[i][j] == 1) {
                if (neighbours == 2 || neighbours == 3)
                    result_matrix[i][j] = 1;
                else
                    result_matrix[i][j] = 0;
            } else {
                if (neighbours == 3)
                    result_matrix[i][j] = 1;
                else
                    result_matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = result_matrix[i][j];
        }
    }
}

void user_speed(int *speed) {
    int ch = getch();
    if ((ch == 'A' || ch == 'a') && *speed > MAX_SPEED)
        *speed -= 50;
    else if ((ch == 'Z' || ch == 'z') && *speed < MIN_SPEED)
        *speed += 50;
    else if (ch == ' ')
        *speed = -1;
}