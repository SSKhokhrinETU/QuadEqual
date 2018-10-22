#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

bool isBiQuad = false;

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

void convertStrToMathExp()
{

}

void isExpressionCorrect(short int strBegin, short int strEnd, char(&string)[151])
{
	short int symbolptr = 0, symbol = 6;
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
				(string[i - 1] == 40))
			{
				if (isBiQuad)
					if (string[i + 1] != 94)
						cout << '\n' << "Mistake: incorrect exponent: " << string[i];
			} else {
				cout << '\n' << "Incorrect input: " << string[i];
			}
			break;
		case 1:
			if (((string[i - 1] > 47) && 
				 (string[i - 1] < 58)) || 
				((string[i - 1] == 42) ||
				 (string[i - 1] == 43) ||	
				 (string[i - 1] == 45) ||	
				 (string[i - 1] == 94))||
				 (string[i - 1] == 0))
			{

			} else {
				cout << '\n' << "Incorrect input: " << string[i];
			}
			break;
		case 2:
			for (int j = i + 1; j < strEnd + 1; j++)
				if (string[j] == 41)
				{
					isExpressionCorrect(i + 1, j - 1, string);
					i = j + 1;
					break;
				}
				else if (j == 150)
					cout << '\n' << "Mistake: expected ')': " << string[i];
			break;
		case 3:
			if (((string[i - 1] > 47) && (string[i - 1] < 58)) || (string[i - 1] == 120) || (string[i - 1] == 41))
			{

			} else {
				cout << '\n' << "Mistake: incorrect syntax of operation: " << string[i];
			}
			break;
		case 4:
			if ((string[i - 1] == 120) && ((string[i + 1] == 50) || (string[i + 1] == 52)))
			{
				if (string[i + 1] == 52)
					isBiQuad = true;
			} else {
				cout << '\n' << "Mistake: incorrect exponent: " << string[i];
			}
			break;
		case -1:
			cout << '\n' << "Incorrect input: " << string[i];
		}
	}
}

int main()
{
	char expression[151] = {0};
	short int symbolcounter = 1, ch = 0;

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
		if ((ch == 8) && (symbolcounter > 0))
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

	isExpressionCorrect(1, 150, expression);
	system("cls");
	equationOutput(expression);
	isExpressionCorrect(1, 150, expression);
	return 0;
}
