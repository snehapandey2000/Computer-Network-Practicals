#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
void rectangle3d(int x1, int y1, int x2, int y2)
{
    rectangle(x1, y1, x2, y2);
    line(x1, y1, x1 + 10, y1 - 10);
    line(x2, y2, x2 + 10, y2 - 10);
    line(x2, y1, x2 + 10, y1 - 10);
    line(x1 + 10, y1 - 10, x2 + 10, y1 - 10);
    line(x2 + 10, y2 - 10, x2 + 10, y1 - 10);
}

void arrow(int x1, int y1, int x2, int y2)
{
    setcolor(WHITE);
    while (y1 != y2)
    {
        line(x1, y1, x2, y1++);
    }
    line(x2, y2, x2 + 10, y2 - 20);
    line(x2, y2, x2 - 10, y2 - 20);
}
void upArrow(int x1, int y1, int x2, int y2)
{
    setcolor(WHITE);
    while (y1 != y2)
    {
        line(x1, y1, x2, y1--);
    }
    line(x2, y2, x2 + 10, y2 + 20);
    line(x2, y2, x2 - 10, y2 + 20);
}
void sideArrow(int x1, int y1, int x2, int y2)
{
    setcolor(WHITE);
    while (x1 != x2)
    {
        line(x1, y1, x1++, y2);
    }
    line(x2, y2, x2 - 20, y2 - 10);
    line(x2, y2, x2 - 20, y2 + 10);
}
void diagram()
{
    for (int i = 0; i < 2; i++)
    {
        setfillstyle(HATCH_FILL, RED);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 70, "application");
        setcolor(1);
        rectangle3d(100 + 900 * i, 50, 300 + 900 * i, 100);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 170, "presentation");
        setcolor(2);
        rectangle3d(100 + 900 * i, 150, 300 + 900 * i, 200);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 270, "session");
        setcolor(3);
        rectangle3d(100 + 900 * i, 250, 300 + 900 * i, 300);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 370, "transport");
        setcolor(4);
        rectangle3d(100 + 900 * i, 350, 300 + 900 * i, 400);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 470, "network");

        setcolor(5);
        rectangle3d(100 + 900 * i, 450, 300 + 900 * i, 500);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 570, "data Link");
        setcolor(6);
        rectangle3d(100 + 900 * i, 550, 300 + 900 * i, 600);
        setcolor(WHITE);
        outtextxy((100 + 900 * i) + 50, 670, "physical");
        setcolor(7);
        rectangle3d(100 + 900 * i, 650, 300 + 900 * i, 700);
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            setcolor(j + 1);
            rectangle(450 + 10 * j, 50 + 100 * i, 460 + 10 * j, 100 + 100 * i);
            if (j == i)
            {
                setcolor(WHITE);
                delay(100);
                outtextxy(470 + 10 * j, 70 + 100 * i, "data");
                rectangle(460 + 10 * j, 50 + 100 * i, 550 + 10 * j, 100 + 100 * i);
            }
        }

        if (i != 6)
        {
            arrow(500, 100 + 100 * i, 500, 150 + 100 * i);
        }
    }
    sideArrow(610, 675, 750, 675);
    for (int i = 6; i >= 0; i--)
    {

        for (int j = 0; j < i; j++)
        {

            setcolor(j + 1);
            rectangle(750 + 10 * j, 50 + 100 * i, 760 + 10 * j, 100 + 100 * i);
            if (j == i - 1)
            {
                setcolor(WHITE);
                outtextxy(780 + 10 * j, 70 + 100 * i, "data");
                rectangle(760 + 10 * j, 50 + 100 * i, 860 + 10 * j, 100 + 100 * i);
            }
        }

        if (i != 0)
        {
            upArrow(800, 150 + 100 * (i - 1), 800, 100 + 100 * (i - 1));
        }
    }
    outtextxy(780, 70, "data");
    rectangle(760, 50, 860, 100);
}

int main()
{
    initwindow(2000, 2000);
    diagram();
    getch();
    closegraph();
    return 0;
}
