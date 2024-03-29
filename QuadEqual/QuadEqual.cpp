#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool isBiQuad = false;
int a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;
float root1 = 0, root2 = 0, root3 = 0, root4 = 0, top = 0;
int number = 0, tempNumber = 0;
int tempA = 1, tempB = 1, tempC = 1, tempZ = 1;
float a = 0, b = 0, c = 0, z = 1, ta, tb, tc, tz, Ta = 0, Tb = 0, Tc = 0;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void solving(float a, float b, float c)
{
	float discriminant = b * b - 4 * a * c;

	if ((discriminant >= 0))
	{
		root1 = root3 = (-b - sqrt(discriminant)) / (2 * a);
		root2 = root4 = (-b + sqrt(discriminant)) / (2 * a);
		if (isBiQuad)
		{
			if (root1 >= 0)
			{
				root1 = -sqrt(root1);
				root3 = -root1;
			}
			else
				root3 = root1;
			if (root2 >= 0)
			{
				root2 = -sqrt(root2);
				root4 = -root2;
			}
			else
				root4 = root2;
		}
		if (!isBiQuad)
			top = -b / (2 * a);
		else
			top = (root4 - root2) / 2;
	}
	else
		cout << '\n' << "No roots";
	if (a == 0) {
		root4 = root3 = root2 = root1 = -c / b;
		if ((b == 0) && (c != 0))
			cout << '\n' << "No roots";
	}
	if ((a == 0) && (b == 0) && (c == 0))
		cout << "...";
}

void graphik()
{
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0, p9 = 0, p10 = 0;
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, top = 0;
	int Y = 0, extY = 0;
	int coordX = 0;

	float arr[4] = { root1, root2, root3, root4 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
			}
		}
	}
	x1 = (int)arr[0];
	x2 = (int)arr[1];
	if ((x1 == x2) && (arr[0] != arr[1]))
		x1--;
	x3 = (int)arr[2];
	if ((x3 <= x2 + 1) && (arr[1] != arr[2]))
		x3 = x2 + 2;
	x4 = (int)arr[3];
	if ((x4 <= x3) && (arr[2] != arr[3]))
		x4 = x3 + 1;
	top = (x1 + x4) / 2;

	float i = x1;
	while (i < x4)
	{
		Y = a * pow(i, (isBiQuad ? 4 : 2)) + b * pow(i, (isBiQuad ? 2 : 1)) + c;
		if (a > 0)
			if (Y > extY)
			{
				extY = Y;
			}
			else if (Y < extY)
				extY = Y;
		i += (x4 - x1) / 100.0;
	}

	p1 = a * pow(x1 - 3, (isBiQuad ? 4 : 2)) + b * pow(x1 - 3, (isBiQuad ? 2 : 1)) + c;
	p2 = a * pow(x1 - 2, (isBiQuad ? 4 : 2)) + b * pow(x1 - 2, (isBiQuad ? 2 : 1)) + c;
	p3 = a * pow(x1 - 1, (isBiQuad ? 4 : 2)) + b * pow(x1 - 1, (isBiQuad ? 2 : 1)) + c;
	p4 = a * pow(x1, (isBiQuad ? 4 : 2)) + b * pow(x1, (isBiQuad ? 2 : 1)) + c;
	p5 = a * pow(extY, (isBiQuad ? 4 : 2)) + b * pow(extY, (isBiQuad ? 2 : 1)) + c;
	p6 = a * pow(top, (isBiQuad ? 4 : 2)) + b * pow(top, (isBiQuad ? 2 : 1)) + c;

	if (isBiQuad || (-x1 == x4))
		coordX = 41;
	else if (0 < x1 - 3)
		coordX = 0;
	else if (0 < x1 - 2)
		coordX = 4;
	else if (0 < x1 - 1)
		coordX = 9;
	else if (0 < x1)
		coordX = 16;
	else if (0 < top)
		coordX = 31;
	else if (0 < x4)
		coordX = 51;
	else if (0 < x4 + 1)
		coordX = 66;
	else if (0 < x4 + 2)
		coordX = 73;
	else if (0 < x4 + 3)
		coordX = 78;
	else
		coordX = 82;


	system("cls");
	for (int i = 1; i < 38; i++)
	{
		gotoxy(coordX, i);
		cout << '\xBA';
	}

	if ((isBiQuad) && (b != 0))
	{
		if ((x1 == x2) && (x3 == x4))
			if (((a > 0) && (p6 > p4)) || ((a < 0) && (p6 < p4)))
			{
				//1
				for (int i = 0; i < 82; i++) {
					gotoxy(i, (a > 0) ? 37 : 1);
					cout << '\xCD';
				}
				gotoxy(1, (a > 0) ? 1 : 37);
				cout << '\xFE';
				gotoxy(6, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(21, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(31, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(41, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(51, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(61, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(76, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(81, (a > 0) ? 1 : 37);
				cout << '\xFE';

				gotoxy(1, (a > 0) ? 38 : 2);
				cout << p1;
				gotoxy(6, (a > 0) ? 38 : 2);
				cout << p2;
				gotoxy(21, (a > 0) ? 38 : 2);
				cout << p3;
				gotoxy(31, (a > 0) ? 38 : 2);
				cout << p4;
				gotoxy(41, (a > 0) ? 38 : 2);
				cout << p6;
				gotoxy(51, (a > 0) ? 38 : 2);
				cout << p4;
				gotoxy(61, (a > 0) ? 38 : 2);
				cout << p3;
				gotoxy(76, (a > 0) ? 38 : 2);
				cout << p2;
				gotoxy(81, (a > 0) ? 38 : 2);
				cout << p1;
			}
			else if (p6 == p4) {
				//3
				for (int i = 0; i < 82; i++) {
					gotoxy(i, (a > 0) ? 25 : 13);
					cout << '\xCD';
				}

				gotoxy(1, (a > 0) ? 1 : 37);
				cout << '\xFE';
				gotoxy(6, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(11, (a > 0) ? 13 : 25);
				cout << '\xFE';
				gotoxy(21, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(31, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(41, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(51, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(61, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(71, (a > 0) ? 13 : 25);
				cout << '\xFE';
				gotoxy(76, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(81, (a > 0) ? 1 : 37);
				cout << '\xFE';

				gotoxy(1, (a > 0) ? 26 : 14);
				cout << p1;
				gotoxy(6, (a > 0) ? 26 : 14);
				cout << p2;
				gotoxy(11, (a > 0) ? 26 : 14);
				cout << p3;
				gotoxy(21, (a > 0) ? 26 : 14);
				cout << p4;
				gotoxy(31, (a > 0) ? 26 : 14);
				cout << p5;
				gotoxy(41, (a > 0) ? 26 : 14);
				cout << p4;
				gotoxy(51, (a > 0) ? 26 : 14);
				cout << p5;
				gotoxy(61, (a > 0) ? 26 : 14);
				cout << p4;
				gotoxy(71, (a > 0) ? 26 : 14);
				cout << p3;
				gotoxy(76, (a > 0) ? 26 : 14);
				cout << p2;
				gotoxy(81, (a > 0) ? 26 : 14);
				cout << p1;
			}
			else
			{
				//4
				for (int i = 0; i < 82; i++) {
					gotoxy(i, 19);
					cout << '\xCD';
				}

				gotoxy(1, (a > 0) ? 1 : 37);
				cout << '\xFE';
				gotoxy(1, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(11, (a > 0) ? 13 : 25);
				cout << '\xFE';
				gotoxy(16, 19);
				cout << '\xFE';
				gotoxy(31, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(41, (a > 0) ? 25 : 13);
				cout << '\xFE';
				gotoxy(51, (a > 0) ? 37 : 1);
				cout << '\xFE';
				gotoxy(66, 19);
				cout << '\xFE';
				gotoxy(71, (a > 0) ? 13 : 25);
				cout << '\xFE';
				gotoxy(76, (a > 0) ? 7 : 31);
				cout << '\xFE';
				gotoxy(81, (a > 0) ? 1 : 37);
				cout << '\xFE';

				gotoxy(1, 20);
				cout << p1;
				gotoxy(6, 20);
				cout << p2;
				gotoxy(11, 20);
				cout << p3;
				gotoxy(16, 20);
				cout << p4;
				gotoxy(31, 20);
				cout << p5;
				gotoxy(41, 20);
				cout << p6;
				gotoxy(51, 20);
				cout << p5;
				gotoxy(66, 20);
				cout << p4;
				gotoxy(71, 20);
				cout << p3;
				gotoxy(76, 20);
				cout << p2;
				gotoxy(81, 20);
				cout << p1;
			}
		else
		{
			//2
			for (int i = 0; i < 82; i++) {
				gotoxy(i, (a > 0) ? 7 : 31);
				cout << '\xCD';
			}

			gotoxy(1, (a > 0) ? 1 : 37);
			cout << '\xFE';
			gotoxy(6, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(11, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(26, ((a > 0) ? 31 : 7));
			cout << '\xFE';
			gotoxy(31, (a > 0) ? 37 : 1);
			cout << '\xFE';
			gotoxy(36, (a > 0) ? 31 : 7);
			cout << '\xFE';
			gotoxy(41, (a > 0) ? 25 : 13);
			cout << '\xFE';
			gotoxy(46, (a > 0) ? 31 : 7);
			cout << '\xFE';
			gotoxy(51, (a > 0) ? 37 : 1);
			cout << '\xFE';
			gotoxy(56, (a > 0) ? 31 : 7);
			cout << '\xFE';
			gotoxy(71, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(76, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(81, (a > 0) ? 1 : 37);
			cout << '\xFE';

			gotoxy(1, (a > 0) ? 8 : 32);
			cout << p1;
			gotoxy(6, (a > 0) ? 8 : 32);
			cout << p2;
			gotoxy(11, (a > 0) ? 8 : 32);
			cout << p3;
			gotoxy(26, (a > 0) ? 8 : 32);
			cout << p4;
			gotoxy(31, (a > 0) ? 8 : 32);
			cout << p5;
			gotoxy(36, (a > 0) ? 8 : 32);
			cout << p4;
			gotoxy(41, (a > 0) ? 8 : 32);
			cout << p6;
			gotoxy(46, (a > 0) ? 8 : 32);
			cout << p4;
			gotoxy(51, (a > 0) ? 8 : 32);
			cout << p5;
			gotoxy(56, (a > 0) ? 8 : 32);
			cout << p4;
			gotoxy(71, (a > 0) ? 8 : 32);
			cout << p3;
			gotoxy(76, (a > 0) ? 8 : 32);
			cout << p2;
			gotoxy(81, (a > 0) ? 8 : 32);
			cout << p1;
		}

	}
	else {
		if (p6 == p4)
		{
			//5
			for (int i = 0; i < 82; i++) {
				gotoxy(i, (a > 0) ? 37 : 1);
				cout << '\xCD';
			}

			gotoxy(1, (a > 0) ? 1 : 37);
			cout << '\xFE';
			gotoxy(6, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(11, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(41, (a > 0) ? 37 : 1);
			cout << '\xFE';
			gotoxy(71, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(76, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(81, (a > 0) ? 1 : 37);
			cout << '\xFE';

			gotoxy(1, (a > 0) ? 38 : 2);
			cout << p1;
			gotoxy(6, (a > 0) ? 38 : 2);
			cout << p2;
			gotoxy(11, (a > 0) ? 38 : 2);
			cout << p3;
			gotoxy(41, (a > 0) ? 38 : 2);
			cout << p4;
			gotoxy(71, (a > 0) ? 38 : 2);
			cout << p3;
			gotoxy(76, (a > 0) ? 38 : 2);
			cout << p2;
			gotoxy(81, (a > 0) ? 38 : 2);
			cout << p1;
		}
		else
		{
			//6
			for (int i = 0; i < 82; i++) {
				gotoxy(i, (a > 0) ? 31 : 7);
				cout << '\xCD';
			}

			gotoxy(1, (a > 0) ? 1 : 37);
			cout << '\xFE';
			gotoxy(6, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(11, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(21, (a > 0) ? 25 : 13);
			cout << '\xFE';
			gotoxy(41, (a > 0) ? 37 : 1);
			cout << '\xFE';
			gotoxy(61, (a > 0) ? 25 : 13);
			cout << '\xFE';
			gotoxy(71, (a > 0) ? 13 : 25);
			cout << '\xFE';
			gotoxy(76, (a > 0) ? 7 : 31);
			cout << '\xFE';
			gotoxy(81, (a > 0) ? 1 : 37);
			cout << '\xFE';

			gotoxy(1, (a < 0) ? 8 : 32);
			cout << p1;
			gotoxy(6, (a < 0) ? 8 : 32);
			cout << p2;
			gotoxy(11, (a < 0) ? 8 : 32);
			cout << p3;
			gotoxy(21, (a < 0) ? 8 : 32);
			cout << p4;
			gotoxy(41, (a < 0) ? 8 : 32);
			cout << p6;
			gotoxy(61, (a < 0) ? 8 : 32);
			cout << p4;
			gotoxy(71, (a < 0) ? 8 : 32);
			cout << p3;
			gotoxy(76, (a < 0) ? 8 : 32);
			cout << p2;
			gotoxy(81, (a < 0) ? 8 : 32);
			cout << p1;
		}
	}

	gotoxy(0, 40);
}

void equationOutput(char(&string)[151])
{
	cout << '\n' << "Equation:" << '\n';
	int i = 1;
	while (string[i] != 0)
	{
		cout << string[i];
		i++;
	}
	cout << "=0";
}

void tConvertM(char(&str)[151], int begin, int end)
{
	for (int i = begin - 1; i < end + 1; i++)
	{
		if (str[i] == 97)
			str[i] = 0;
	}
	char a_s[11], b_s[11], c_s[11], z_s[11];
	int stop = begin + 2;
	for (int i = begin + 3; i < end; i++)
	{
		if (str[i] == 121)
		{
			int j = stop;
			if (str[j] == 0)
				stop = ++j;
			if (str[j] == 45)
			{
				a_s[j - stop] = str[j];
				j++;
				if (str[j] == 121) {
					tempA = -tempA;
					if ((str[j + 1] != 42))
						j += 2;
				}
			}
			if ((str[j] == 121) && (str[j + 1] != 42))
				j += 1;
			while ((str[j] != 0) && (str[j] != 32))
			{
				if (str[j] == 121)
				{
					j += 1;
					if (str[j + 1] != 42)
						j--;
				}
				if (str[j] != 0)
					a_s[j - stop] = str[j];

				if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
				{
					ta = atoi(a_s);
					if (ta != 0)
						tempA *= ta;
					ta = 0;
					for (int i = 0; i < 11; i++)
						a_s[i] = 0;
					j++;
					stop = j + 1;
				}
				j++;
			}
			if (str[j + 2] == 45)
				j++;
			i = j + 1;

			stop = i;
			Ta += tempA;
			tempA = 1;
		}
		if (str[i] == 120)
		{
			int j = stop;
			if (str[j] == 0)
				stop = ++j;
			if (str[j] == 45)
			{
				b_s[j - stop] = str[j];
				j++;
				if (str[j] == 120)
				{
					tempB = -tempB;
					if ((str[j + 1] != 42))
						j += 2;
				}
			}
			if ((str[j] == 120) && (str[j + 1] != 42))
				j += 1;
			while ((str[j] != 0) && (str[j] != 32))
			{
				if (str[j] == 120)
				{
					j++;
					if (str[j + 1] != 42)
						j--;
				}
				if (str[j] != 0)
					b_s[j - stop] = str[j];

				if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
				{
					tb = atoi(b_s);
					if (tb != 0)
						tempB *= tb;
					tb = 0;
					for (int i = 0; i < 11; i++)
						b_s[i] = 0;
					j++;
					stop = j + 1;
				}
				j++;
			}
			if (str[j + 2] == 45)
				j++;
			i = j + 1;
			stop = i;
			Tb += tempB;
			tempB = 1;
		}
		if ((str[i] == 45) || ((str[i] > 47) && (str[i] < 58)))
		{
			bool isC = true;
			if ((str[i] == 45) || ((str[i] > 47) && (str[i] < 58)))
			{
				int j = i;
				if ((str[j] == 45) || (str[j] == 0) || (str[j] == 32))
					j++;
				while ((str[j] != 32) && (str[j] != 0))
				{
					if ((str[j] == 121) || (str[j] == 120) || (str[j] == 40))
						isC = false;
					j++;
				}
				if (str[i - 1] == 45)
					j--;

			}
			if (isC) {

				int j = stop;
				if ((str[j] == 0) || (str[j] == 32))
					stop = ++j;

				if (str[j] == 45)
				{
					c_s[j - stop] = str[j];
					j++;

				}

				while ((str[j] != 0) && (str[j] != 32))
				{

					if (str[j] != 0)
						c_s[j - stop] = str[j];

					if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
					{
						tc = atoi(c_s);
						if (tc != 0)
							tempC *= tc;
						tc = 0;
						for (int i = 0; i < 11; i++)
							c_s[i] = 0;
						j++;
						stop = j + 1;
					}
					j++;
				}
				if (str[j + 2] == 45)
					j++;
				i = j + 1;
				stop = i;
				Tc += tempC;
				tempC = 1;
			}
		}
		if (str[i] == 0)
			break;
	}
	for (int i = begin - 1; i < end + 1; i++)
	{
		if (str[i] == 0)
			str[i] = 97;
	}
}

void convertM(char(&str)[151])
{
	char a_s[11], b_s[11], c_s[11], z_s[11];
	int stop = 0;
	for (int i = 1; i < 150; i++)
	{
		if (str[i] == 121)
		{
			int j = stop;
			if (str[j] == 0)
				stop = ++j;
			if (str[j] == 45)
			{
				a_s[j - stop] = str[j];
				j++;
				if (str[j] == 121) {
					tempA = -tempA;
					if ((str[j + 1] != 42))
						j += 2;
				}
			}
			if ((str[j] == 121) && (str[j + 1] != 42))
				j += 1;
			while ((str[j] != 0) && (str[j] != 32))
			{
				if (str[j] == 121)
				{
					j += 1;
					if (str[j + 1] != 42)
						j--;
				}
				if (str[j] != 0)
					a_s[j - stop] = str[j];

				if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
				{
					ta = atoi(a_s);
					if (ta != 0)
						tempA *= ta;
					ta = 0;
					for (int i = 0; i < 11; i++)
						a_s[i] = 0;
					j++;
					stop = j + 1;
				}
				j++;
			}
			if (str[j + 2] == 45)
				j++;
			i = j + 1;

			stop = i;
			a += tempA;
			tempA = 1;
		}
		if (str[i] == 120)
		{
			int j = stop;
			if (str[j] == 0)
				stop = ++j;
			if (str[j] == 45)
			{
				b_s[j - stop] = str[j];
				j++;
				if (str[j] == 120)
				{
					tempB = -tempB;
					if ((str[j + 1] != 42))
						j += 2;
				}
			}
			if ((str[j] == 120) && (str[j + 1] != 42))
				j += 1;
			while ((str[j] != 0) && (str[j] != 32))
			{
				if (str[j] == 120)
				{
					j++;
					if (str[j + 1] != 42)
						j--;
				}
				if (str[j] != 0)
					b_s[j - stop] = str[j];

				if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
				{
					tb = atoi(b_s);
					if (tb != 0)
						tempB *= tb;
					tb = 0;
					for (int i = 0; i < 11; i++)
						b_s[i] = 0;
					j++;
					stop = j + 1;
				}
				j++;
			}
			if (str[j + 2] == 45)
				j++;
			i = j + 1;
			stop = i;
			b += tempB;
			tempB = 1;
		}
		if ((str[i] == 45) || ((str[i] > 47) && (str[i] < 58)))
		{
			bool isC = true;
			if ((str[i] == 45) || ((str[i] > 47) && (str[i] < 58)))
			{
				int j = i;
				if ((str[j] == 45) || (str[j] == 0) || (str[j] == 32))
					j++;
				while ((str[j] != 32) && (str[j] != 0))
				{
					if ((str[j] == 121) || (str[j] == 120) || (str[j] == 40))
						isC = false;
					j++;
				}
				if (str[i - 1] == 45)
					j--;

			}
			if (isC) {

				int j = stop;
				if ((str[j] == 0) || (str[j] == 32))
					stop = ++j;

				if (str[j] == 45)
				{
					c_s[j - stop] = str[j];
					j++;

				}

				while ((str[j] != 0) && (str[j] != 32))
				{

					if (str[j] != 0)
						c_s[j - stop] = str[j];

					if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
					{
						tc = atoi(c_s);
						if (tc != 0)
							tempC *= tc;
						tc = 0;
						for (int i = 0; i < 11; i++)
							c_s[i] = 0;
						j++;
						stop = j + 1;
					}
					j++;
				}
				if (str[j + 2] == 45)
					j++;
				i = j + 1;

				stop = i;
				c += tempC;
				tempC = 1;

			}
		}
		if (str[i] == 40)
		{
			int j = stop, b_close = i;
			while (str[b_close] != 41)
				b_close++;
			if ((str[j] == 0) || (str[j] == 32))
				stop = ++j;
			if (str[j] == 45)
			{
				z_s[j - stop] = str[j];
				j++;
				if (str[j] == 40) {
					tempZ = -tempZ;
					if ((str[b_close + 1] != 42))
						j = b_close + 2;
				}

			}
			if ((str[j] == 40) && (str[b_close + 1] != 42))
				j = b_close + 1;
			while ((str[j] != 0) && (str[j] != 32))
			{
				if ((str[j] == 40) && (str[b_close + 1] != 42))
				{
					j = b_close + 1;
					stop = j;
					if ((str[j - 1] == 41) && (str[j] != 42))
					{
						j++;
						if (str[j] == 32)
							break;
					}
				}
				if (str[j] == 40) {
					j = b_close + 2; stop = j;
				}

				if (str[j] != 0)
					z_s[j - stop] = str[j];

				if ((str[j + 1] == 42) || (str[j + 1] == 0) || (str[j + 1] == 32) || (str[j + 1] == 45))
				{
					tz = atoi(z_s);
					if (tz != 0)
						tempZ *= tz;
					tz = 0;
					for (int i = 0; i < 11; i++)
						z_s[i] = 0;
					j++;
					stop = j + 1;
				}
				j++;
				if ((str[j - 1] == 32))
					break;
			}
			tConvertM(str, i, b_close - 1);

			a += Ta * tempZ;
			b += Tb * tempZ;
			c += Tc * tempZ;
			Ta = Tb = Tc = 0;
			tempZ = 1;

			if (str[j + 2] == 45)
				j++;
			i = j + 1;
			stop = i;
		}
		if (str[i] == 0)
			break;
	}
}

void convert(char(&string)[151])
{
	if (!isBiQuad)
	{
		for (int i = 1; i < 150; i++)
		{
			if (string[i + 1] == 94)
			{
				string[i] = 121;
				for (int j = i + 3; j < 150; j++)
				{
					string[j - 2] = string[j];
				}
			}
		}
	}
	else
	{
		for (int i = 1; i < 150; i++)
		{
			if (string[i + 1] == 94)
			{
				if (string[i + 2] == 52)
				{
					string[i] = 121;
					for (int j = i + 3; j < 150; j++)
					{
						string[j - 2] = string[j];
					}
				}
				else
				{
					for (int j = i + 3; j < 150; j++)
					{
						string[j - 2] = string[j];
					}
				}
			}
		}
	}
	for (int i = 2; i < 150; i++)
	{
		if ((string[i] == 43) || (string[i] == 45))
		{
			for (int j = 150; j > i; j--)
				string[j] = string[j - 2];
			string[i] = 32;
			string[i + 1] = 32;
			i += 3;
		}
		if ((string[i] == 41))
		{
			for (int j = 150; j > i; j--)
				string[j] = string[j - 3];
			string[i] = 97;
			string[i + 1] = 97;
			string[i + 2] = 97;
			i += 3;
		}
		if ((string[i - 1] == 40))
		{
			for (int j = 150; j > i + 1; j--)
				string[j] = string[j - 2];
			string[i] = 97;
			string[i + 1] = 97;
			i += 2;
		}
		if ((string[i] == 43) || (string[i] == 45))
		{
			for (int j = 150; j > i; j--)
				string[j] = string[j - 2];
			string[i] = 32;
			string[i + 1] = 32;
			i += 3;
		}
	}
}

bool isExpressionCorrect(short int strBegin, short int strEnd, char(&string)[151])
{
	bool isCorrect = false;
	short int symbolptr = 0, symbol = 0;
	for (int i = strBegin; i < strEnd; i++)
	{
		if (string[i] == 120)							//is x					
			symbol = 0;
		else if ((string[i] > 47) && (string[i] < 58))	//is number				
			symbol = 1;
		else if (string[i] == 40)						//is bracket						
			symbol = 2;
		else if ((string[i] == 42) ||		//*
			(string[i] == 43) ||		//+
			(string[i] == 45))			//-
			symbol = 3;
		else if (string[i] == 94)			//^
			symbol = 4;
		else if (string[i] == 0)
			break;
		else
			symbol = -1;

		switch (symbol)
		{
		case 0:
			if ((string[i - 1] == 42) ||
				(string[i - 1] == 43) ||
				(string[i - 1] == 45) ||
				(string[i - 1] == 40) ||
				(string[i - 1] == 0))
			{
				isCorrect = true;
				if (isBiQuad)
					if (string[i + 1] != 94)
					{
						cout << '\n' << "Mistake: incorrect exponent: " << string[i - 1] << string[i] << string[i + 1];
						isCorrect = false;
					}
			}
			else {
				cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
				isCorrect = false;
			}
			break;
		case 1:
			if (((string[i - 1] > 47) &&
				(string[i - 1] < 58)) ||
				((string[i - 1] == 42) ||
				(string[i - 1] == 43) ||
					(string[i - 1] == 45) ||
					(string[i - 1] == 94) ||
					(string[i - 1] == 40) ||
					(string[i - 1] == 0)))
			{
				isCorrect = true;
			}
			else {
				cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
				isCorrect = false;
			}
			break;
		case 2:
			for (int j = i + 1; j < strEnd + 1; j++)
				if (string[j] == 41)
				{
					isExpressionCorrect(i + 1, j - 1, string);
					i = j + 1;
					break;
					isCorrect = true;
				}
				else if (j == 150)
				{
					cout << '\n' << "Mistake: expected ')'";
					isCorrect = false;
				}
			break;
		case 3:
			if ((((string[i - 1] > 47) && (string[i - 1] < 58)) || (string[i - 1] == 120) || (string[i - 1] == 41)) && (string[i + 1] != 0))
			{
				isCorrect = true;
			}
			else {
				cout << '\n' << "Mistake: incorrect syntax of operation: " << string[i - 1] << string[i] << string[i + 1];
				isCorrect = false;
			}
			break;
		case 4:
			if ((string[i - 1] == 120) && ((string[i + 1] == 50) || (string[i + 1] == 52)))
			{
				isCorrect = true;

				if (string[i + 1] == 52)
					isBiQuad = true;
			}
			else {
				cout << '\n' << "Mistake: incorrect exponent: " << string[i - 1] << string[i] << string[i + 1];
				isCorrect = false;
			}
			i++;
			break;
		case -1:
			cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
			isCorrect = false;
		}
	}
	return isCorrect;
}

int main()
{
	char expression[151] = { 0 };
	short int symbolcounter = 1, ch = 0;
	bool isCorrect = false;
	while (!isCorrect)
	{
		system("cls");
		ch = 0;
		while ((symbolcounter < 151) && (ch != 13) && (ch != 27))
		{
			system("cls");
			cout << "Equation input:" << '\n' << "0=";
			for (int i = 1; i < 150; i++)
			{
				cout << expression[i];
				if (expression[i + 1] == 0)
					break;
			}
			ch = _getch();
			if ((ch == 8) && (symbolcounter > 1))
			{
				symbolcounter--;
				expression[symbolcounter] = 0;
			}
			if ((ch >= 32) && (ch <= 252))
			{
				if (ch != 224)
				{
					expression[symbolcounter] = ch;
					symbolcounter++;
				}
				else if (!_getch())
				{
					expression[symbolcounter] = ch;
					symbolcounter++;
				}
			}
		}
		isCorrect = isExpressionCorrect((expression[1] == 45 ? 2 : 1), 150, expression);
		isCorrect = isExpressionCorrect((expression[1] == 45 ? 2 : 1), 150, expression);
		cout << '\n';
		system("pause");
	}
	system("cls");
	equationOutput(expression);
	expression[symbolcounter] = 43;
	expression[symbolcounter + 1] = 47;
	convert(expression);
	cout << '\n';
	convertM(expression);
	solving(a, b, c);

	cout << endl << endl << "Roots:" << endl;
	cout << "x1 = " << root1;
	if (root2 != root1)
		cout << "; x2 = " << root2;
	if ((root3 != root2) && (root3 != root1))
		cout << "; x3 = " << root3;
	if ((root4 != root1) && (root4 != root2) && (root4 != root3))
		cout << "; x4 = " << root4 << endl;
	system("pause");
	if (a != 0)
		graphik();
	return 0;
}