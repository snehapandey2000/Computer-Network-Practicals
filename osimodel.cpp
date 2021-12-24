#include <graphics.h>
#include <bits/stdc++.h>
void DDA(int type, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xin = dx / float(steps);
	float yin = dy / float(steps);

	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++)
	{
		putpixel(x, y, 14);
		if (type == 1)
		{
			putpixel(x + 35, y, 14);
			putpixel(x + 70, y, 14);
			delay(10);
		}
		else
			delay(5);
		x += xin;
		y += yin;
	}
}

void drawArrows(int side, int num)
{
	int h = 55, t = 1;
	int x, y, x2, y2, lx, ly, rx, ry;
	if (side == 1)
	{
		x = 245;
		switch (num)
		{
		case 1:
			y = 95;
			break;
		case 2:
			y = 195;
			break;
		case 3:
			y = 295;
			break;
		case 4:
			y = 395;
			break;
		case 5:
			y = 495;
			break;
		case 6:
			y = 595;
			break;
		};
	}
	else
	{
		t = -1;
		x = 795;
		switch (num)
		{
		case 1:
			y = 95 + h;
			break;
		case 2:
			y = 195 + h;
			break;
		case 3:
			y = 295 + h;
			break;
		case 4:
			y = 395 + h;
			break;
		case 5:
			y = 495 + h;
			break;
		case 6:
			y = 595 + h;
			break;
		};
	}

	x2 = x;
	y2 = y + (t * h);
	lx = x2 - 10;
	rx = x2 + 10;
	ly = y2 - (t * 10);
	ry = ly;
	//for(int i =0; i<3; i++)
	//{
	DDA(1, x, y, x2, y2);
	setcolor(14);
	line(lx, ly, x2, y2);
	line(rx, ry, x2, y2);
	line(lx + 35, ly, x2 + 35, y2);
	line(rx + 35, ry, x2 + 35, y2);
	delay(300);
	setcolor(0);
	line(x, y, x2, y2);
	line(x + 35, y, x2 + 35, y2);
	line(lx, ly, x2, y2);
	line(rx, ry, x2, y2);
	line(lx + 35, ly, x2 + 35, y2);
	line(rx + 35, ry, x2 + 35, y2);
	line(lx + 70, ly, x2 + 70, y2);
	line(rx + 70, ry, x2 + 70, y2);
}

void datarect(int side, int color)
{
	int x_init = 210, y_init = 55;
	int ylen = 40;
	int rectx1, rectx2;
	setcolor(WHITE);
	if (side == 2)
	{
		x_init = 760;
	}

	rectx1 = x_init + ylen + 15;
	rectx2 = rectx1 + 80 + color * 6;

	y_init = 55 + 100 * (color - 1);
	rectangle(x_init, y_init, x_init + ylen, y_init + ylen);
	rectangle(rectx1, y_init, rectx2, y_init + ylen);
	switch (color)
	{
	case 1:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H1");
		setcolor(15);
		outtextxy(rectx1 + 18, y_init + 10, "D1");
		break;
	case 2:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H2");
		outtextxy(rectx1 + 38, y_init + 10, "D2");
		break;
	case 3:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H3");
		outtextxy(rectx1 + 38, y_init + 10, "D3");
		break;
	case 4:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H4");
		outtextxy(rectx1 + 38, y_init + 10, "D4");
		break;
	case 5:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H5");
		outtextxy(rectx1 + 38, y_init + 10, "D5");
		break;
	case 6:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H6");
		outtextxy(rectx1 + 38, y_init + 10, "D6");
		rectangle(rectx2 + 10, y_init, rectx2 + 10 + ylen, y_init + ylen);
		outtextxy(rectx2 + 18, y_init + 10, "T6");
		break;
	case 7:
		setcolor(15);
		outtextxy(x_init + 10, y_init + 10, "H7");
		outtextxy(rectx1 + 38, y_init + 10, "D7");
		break;
	};
}
void drawArrowHori(int num, int flag)
{
	if (flag == 0)
		return;

	int x1, x2, y, subx1;

	if (num == 1)
	{
		x1 = 400;
		x2 = 550;
		y = 675;
	}
	else if (num == 2)
	{
		x1 = 910;
		x2 = 1060;
		y = 75;
	}

	subx1 = x2 - 10;

	for (int i = 0; i < 3; i++)
	{
		setcolor(14);
		DDA(2, x1, y, x2, y);
		line(subx1, y - 10, x2, y);
		line(subx1, y + 10, x2, y);
		delay(300);
		if (i == 2)
			break;
		setcolor(0);
		line(x1, y, x2, y);
		line(subx1, y - 10, x2, y);
		line(subx1, y + 10, x2, y);
	}
}
int main()
{

	initwindow(1500, 1500);
	int h = 60, w = 150;
	int c, side = 1, flag = 1;
	settextstyle(3, 0, 2);
	outtextxy(60, 20, "SENDER");
	outtextxy(600, 20, "RECIEVER");
	setcolor(WHITE);
	settextstyle(3, 0, 1);
	//SENDER SIDE
	rectangle(50, 50, 150, 100);
	outtextxy(53, 62, "Application");
	rectangle(50, 150, 150, 200);
	outtextxy(53, 162, "Presentation");
	rectangle(50, 250, 150, 300);
	outtextxy(53, 262, "Session");
	rectangle(50, 350, 150, 400);
	outtextxy(53, 362, "Transport");
	rectangle(50, 450, 150, 500);
	outtextxy(53, 462, "Network");
	rectangle(50, 550, 150, 600);
	outtextxy(53, 562, "Data Link");
	rectangle(50, 650, 150, 700);
	outtextxy(53, 662, "Physical");

	//RECIEVER SIDE
	rectangle(600, 50, 700, 100);
	outtextxy(603, 62, "Application");
	rectangle(600, 150, 700, 200);
	outtextxy(603, 162, "Presentation");
	rectangle(600, 250, 700, 300);
	outtextxy(603, 262, "Session");
	rectangle(600, 350, 700, 400);
	outtextxy(603, 362, "Transport");
	rectangle(600, 450, 700, 500);
	outtextxy(603, 462, "Network");
	rectangle(600, 550, 700, 600);
	outtextxy(603, 562, "Data Link");
	rectangle(600, 650, 700, 700);
	outtextxy(603, 662, "Physical");
	//TRANSMISSION MODE
	rectangle(100, 700, 650, 725);
	line(150, 700, 600, 700);

	for (int i = 1; i < 15; i++)
	{
		if (i > 7)
		{
			c = 15 - i;
			side = 2;
		}
		else
			c = i;

		datarect(side, c);
		delay(100);
		if (c == 7)
		{
			drawArrowHori(1, flag);
			flag--;
			continue;
		}

		drawArrows(side, c);
	}
	getch();
	closegraph();
}
