/*#include <stdio.h>
#include <windows.h> 
//нужна для функции Sleep()
#define HEIGHT 25
#define WIDTH 25
#define LIFE_YES 1
#define LIFE_NO 0


typedef int TableType[HEIGHT][WIDTH];

void printTable(TableType table) {
    int height, width;

    for (height = 0; height < HEIGHT; height++) {
        for (width = 0; width < WIDTH; width++) {
            if (table[height][width] == LIFE_YES) {
                printf("X");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}
//Функция выводит игровое поле, там где есть жизнь 'X'
//где нет '.'

void clearTable(TableType table) {
    int height, width;
    for (height = 0; height < HEIGHT; height++) {
        for (width = 0; width < WIDTH; width++) {
            table[height][width] = LIFE_NO;
        }
    }
}
//очищаем наше игровое поле от всех живых клеток


int getNeighborValue(TableType table, int row, int col) {
    if (row < 0 || row >= HEIGHT
        || col < 0 || col >= WIDTH
        || table[row][col] != LIFE_YES)
    {
        return 0;
    }
    else {
        return 1;
    }
}
//если мы вышли за пределы игровой зоны или клетка не жива возвращаем 0
//иначе 1


int getNeighborCount(TableType table, int row, int col) {
    int neighbor = 0;

    neighbor += getNeighborValue(table, row - 1, col - 1);
    neighbor += getNeighborValue(table, row - 1, col);
    neighbor += getNeighborValue(table, row - 1, col + 1);
    neighbor += getNeighborValue(table, row, col - 1);
    neighbor += getNeighborValue(table, row, col + 1);
    neighbor += getNeighborValue(table, row + 1, col - 1);
    neighbor += getNeighborValue(table, row + 1, col);
    neighbor += getNeighborValue(table, row + 1, col + 1);

    return neighbor;
}
//Функция чекает все соседние координаты на наличие соседей

void calculate(TableType tableA) {
    TableType tableB;
    int neighbor, height, width;

    for (height = 0; height < HEIGHT; height++) {
        for (width = 0; width < WIDTH; width++) {
            neighbor = getNeighborCount(tableA, height, width);
            if (neighbor == 3) {
                tableB[height][width] = LIFE_YES;
            }
            else if (neighbor == 2 && tableA[height][width] == LIFE_YES) {
                tableB[height][width] = LIFE_YES;
            }
            else {
                tableB[height][width] = LIFE_NO;
            }
        }
    }
    for (height = 0; height < HEIGHT; height++) {
        for (width = 0; width < WIDTH; width++) {
            tableA[height][width] = tableB[height][width];
        }
    }
}
//в этой функции проверяется выполнение правил игры(можете прочитать на wiki

void loaddata(TableType table) {

    //glider
    table[10][4] = LIFE_YES;
    table[11][5] = LIFE_YES;
    table[12][5] = LIFE_YES;
    table[12][4] = LIFE_YES;
    table[12][3] = LIFE_YES;
}
//Загружаем начальные данные

int main(int argc, char* argv[])
{
    TableType table;
    int generation = 0;
    clearTable(table);
    loaddata(table);
    printTable(table);
    printTable(table);
    for (generation = 0; generation < 100000; generation++)
    {
        calculate(table);
        printTable(table);
        printTable(table);
        printf("Generation %d\n", generation);
        Sleep(500);
        //for(i=0;i<70000000;i++);
        //getchar();
    }
    return 0;
}*/