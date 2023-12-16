
#include<stdio.h>
#include<windows.h>
#define High 25 //Размеры игры
#define Width 50
//Определяем глобальные переменные
int cells[High][Width]; //Клетки живут - 1 мертвы - 0
void HideCursor() //Спрятатать курсор
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y) //Сдвинуть курсор на (x,y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void startup() //Инициализация данных
{
    int i, j;
    for (i = 0; i <= High; i++)
        for (j = 0; j <= Width; j++)
            cells[i][j] = rand() % 2;//Все ячейки изначально рождаются/


    HideCursor();
}
void show() //Интерфейс дисплея
{
    gotoxy(0, 0);
    int i, j;
    for (i = 1; i < High; i++)
    {
        for (j = 0; j < Width; j++)
        {
            if (cells[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    Sleep(200); //Управление скоростью обновления
}
void updateWithoutInput() //Ввод пользователя не требуется
{
    int i, j;
    int NeibourNumber;
    int temp[High][Width];
    for (i = 1; i < High; i++)
    {
        for (j = 1; j < Width; j++)
        {
            NeibourNumber = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1] + cells[i][j - 1] + cells[i][j + 1] + cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];
            if (NeibourNumber == 3) //Когда вокруг 3 живых клетки, клетка растет.
                temp[i][j] = 1;
            else if (NeibourNumber == 2) ////Когда вокруг 2 живые клетки, состояние клетки остается неизменным.
                temp[i][j] = cells[i][j];
            else
                temp[i][j] = 0;
        }
    }
    for (i = 1; i < High; i++)
        for (j = 1; j < Width; j++)
            cells[i][j] = temp[i][j];
}
int main()
{
    startup();
    while (1)
    {
        show();
        updateWithoutInput();
    }
}
