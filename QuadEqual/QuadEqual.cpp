//#include "pch.h"
//#include <iostream>
//#include <conio.h>
//
//using namespace std;
//
//bool isBiQuad = false;
//int a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;
//int root1 = 0, root2 = 0, root3 = 0, root4 = 0, top = 0;
//int number = 0, tempNumber = 0;
//int a = 0, b = 0, c = 0, tempA = 0, tempB = 0, tempC = 0;
//
///*void graphik()
//{
//	int maxX = 0, minX = 0, maxY = 0, minY = 0, RX = 0, RY = 0;
//	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0, p9 = 0, p10 = 0, p11 = 0;
//	
//	if (!isBiQuad)
//	{
//		maxX = (root1 > root2) ? root1 : root2;
//		minX = (root1 < root2) ? root1 : root2;
//	}
//	else
//	{
//		maxX = (root1 > root2) ? ((root1 > root3) ? ((root1 > root4) ? root1 : root4) : ((root3 > root4) ? root3 : root4)) 
//			: ((root2 > root3) ? ((root2 > root4) ? root2 : root4) : ((root3 > root4) ? root3 : root4));
//		minX = (root1 < root2) ? ((root1 < root3) ? ((root1 < root4) ? root1 : root4) : ((root3 < root4) ? root3 : root4))
//			: ((root2 < root3) ? ((root2 < root4) ? root2 : root4) : ((root3 < root4) ? root3 : root4));
//	}
//	p1 = a * pow(minX - 30, (isBiQuad ? 4 : 2)) + b * pow(minX - 30, (isBiQuad ? 2 : 1)) + c;
//	p2 = a * pow(minX - 20, (isBiQuad ? 4 : 2)) + b * pow(minX - 20, (isBiQuad ? 2 : 1)) + c;
//	p3 = a * pow(minX - 10, (isBiQuad ? 4 : 2)) + b * pow(minX - 10, (isBiQuad ? 2 : 1)) + c;
//	p4 = a * pow(maxX + 10, (isBiQuad ? 4 : 2)) + b * pow(maxX + 10, (isBiQuad ? 2 : 1)) + c;
//	p5 = a * pow(maxX + 20, (isBiQuad ? 4 : 2)) + b * pow(maxX + 20, (isBiQuad ? 2 : 1)) + c;
//	p6 = a * pow(maxX + 30, (isBiQuad ? 4 : 2)) + b * pow(maxX + 30, (isBiQuad ? 2 : 1)) + c;
//
//	p7 = a * pow(root1, (isBiQuad ? 4 : 2)) + b * pow(root1, (isBiQuad ? 2 : 1)) + c;
//	p8 = a * pow(root2, (isBiQuad ? 4 : 2)) + b * pow(root2, (isBiQuad ? 2 : 1)) + c;
//	p9 = a * pow(top, (isBiQuad ? 4 : 2)) + b * pow(top, (isBiQuad ? 2 : 1)) + c;
//
//	p10 = a * pow(root3, (isBiQuad ? 4 : 2)) + b * pow(root3, (isBiQuad ? 2 : 1)) + c;
//	p11 = a * pow(root4, (isBiQuad ? 4 : 2)) + b * pow(root4, (isBiQuad ? 2 : 1)) + c;
//
//	int arr[11] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11};
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10 - i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				arr[j] += arr[j + 1];
//				arr[j + 1] = arr[j] - arr[j + 1];
//				arr[j] -= arr[j + 1];
//			}
//		}
//	}
//	minY = arr[0];
//	maxY = arr[10];
//	RX = (maxX + 60 - minX) / 80;
//	RY = (maxY - minY) / 20;
//
//	system("cls");
//	gotoxy((maxX - 30) / RX, );
//}*/
//
//void solving(int a, int b, int c)
//{
//	int discriminant = b * b - 4 * a * c;
//
//	if (discriminant >= 0)
//	{
//		root1 = root3 = (-b - sqrt(discriminant)) / (2 * a);
//		root2 = root4 = (-b + sqrt(discriminant)) / (2 * a);
//		if (isBiQuad)
//		{
//			if (root1 >= 0)
//			{
//				root1 = -sqrt(root1);
//				root3 = -root1;
//			}
//			else
//				root3 = root1;
//			if (root2 >= 0)
//			{
//				root2 = -sqrt(root2);
//				root4 = -root2;
//			}
//			else
//				root4 = root2;	
//		}
//		top = -b / (2 * a);
//	}
//	else
//		cout << '\n' << "D < 0, no roots";
//}
//
//void equationOutput(char(&string)[151])
//{
//	cout << '\n' << "Equation:" << '\n';
//	int i = 1;
//	while (string[i] != 0)
//	{
//		cout << string[i];
//		i++;
//	}
//	cout << "=0";
//}
//
//void convertToNumber(char(&str)[151], short int begin, short int end)
//{
//	for (int i = begin; i < end; i++)
//		number = number * 10 + str[i] - 48;
//}
//
//void nMul()
//{
//
//}
//
///*void tempConvertStrToMathExp(short int strBegin, short int strEnd, char(&string)[151])
//{
//	short int ptrBegin = 0, ptrEnd = 0;
//	for (int i = strBegin; i < strEnd; i++)
//	{
//		if ((string[i] > 47) && (string[i] < 58))
//		{
//			ptrBegin = ptrEnd = i;
//			while ((string[ptrEnd] > 47) && (string[ptrEnd] < 58))
//				ptrEnd++;
//			convertToNumber(string, ptrBegin, ptrEnd);
//			if (string[ptrEnd] != 42)
//			{
//				c += number;
//				number = 0;
//			}
//			else
//			{
//				if (string[ptrEnd + 1] == 120)
//				{
//					if (!isBiQuad)
//					{
//						if (string[ptrEnd + 3] == 94)
//						{
//							a += number;
//							number = 0;
//						}
//						else
//						{
//							b += number;
//							number = 0;
//						}
//					}
//					else if (string[ptrEnd + 4] == 50)
//					{
//						b += number;
//						number = 0;
//					}
//					else
//					{
//						a += number;
//						number = 0;
//					}
//				}
//			}
//		}
//		else
//		{
//
//		}
//	}
//}*/
//
///*void convertStrToMathExp(short int strBegin, short int strEnd, char(&string)[151])
//{
//	short int ptrBegin = 0, ptrEnd = 0;
//	for (int i = strBegin; i < strEnd; i++)
//	{
//		if ((string[i] > 47) && (string[i] < 58))
//		{
//			ptrBegin = ptrEnd = i;
//			while ((string[ptrEnd] > 47) && (string[ptrEnd] < 58))
//				ptrEnd++;
//			convertToNumber(string, ptrBegin, ptrEnd);
//			if (string[ptrEnd] != 42)
//			{
//				c += number;
//				number = 0;
//			}
//			else
//			{
//				if (string[ptrEnd + 1] == 120) 
//				{
//					if (!isBiQuad) 
//					{
//						if (string[ptrEnd + 3] == 94)
//						{
//								a += number;
//								number = 0;
//						}
//						else
//						{
//							b += number;
//							number = 0;
//						}
//					}
//					else if (string[ptrEnd + 4] == 50)
//					{
//						b += number;
//						number = 0;
//					}
//					else
//					{
//						a += number;
//						number = 0;
//					}
//				}
//				else if (string[ptrEnd + 1] == 40)
//				{
//					ptrBegin = ptrEnd;
//					while (string[ptrBegin] != )
//						ptrBegin++;
//					tempConvertStrToMathExp(ptrBegin + 1, ptrEnd, string);
//				}
//			}
//		} 
//		else if (string[i] == 40)
//		{
//
//		} else
//		{
//
//		}
//	}
//}*/
//
//void tConvertM()
//{
//	for (int i = begin; i <end; i++)
//	{
//		if ((equation[i] == 120) && (equation[i + 1] == '^')) {
//			for (int j = 0; j < i - 1; j++)
//			{
//				a_s += equation[j];
//			}
//			stop = i + 3; //Перемещение коретки на 3 знака вперед (^2)
//		}
//		else
//		{
//			if (equation[i] == 120)
//			{
//				for (int j = stop; j < i - 1; j++)
//				{
//					b_s += equation[j];
//				}
//				stop = i + 1;
//			}
//		}
//	}
//}
//
//void convertM()
//{
//
//}
//
//void convert(char(&string)[151])
//{
//	if (!isBiQuad)
//	{
//		for (int i = 1; i < 150; i++)
//		{
//			if (string[i + 1] == 94)
//			{
//				string[i] = 121;
//				for (int j = i + 3; j < 150; j++)
//				{
//					string[j - 2] = string[j];
//				}
//			}
//		}
//	}
//	else
//	{
//		for (int i = 1; i < 150; i++)
//		{
//			if (string[i + 1] == 94)
//			{
//				if (string[i + 2] == 52)
//				{
//					string[i] = 121;
//					for (int j = i + 3; j < 150; j++)
//					{
//						string[j - 2] = string[j];
//					}
//				}
//				else
//				{
//					for (int j = i + 3; j < 150; j++)
//					{
//						string[j - 2] = string[j];
//					}
//				}
//			}
//		}
//	}
//}
//
//bool isExpressionCorrect(short int strBegin, short int strEnd, char(&string)[151])
//{
//	bool isCorrect = false;
//	short int symbolptr = 0, symbol = 0;
//	for (int i = strBegin; i < strEnd; i++)
//	{
//		if (string[i] == 120)							//is x					
//			symbol = 0;
//		else if ((string[i] > 47) && (string[i] < 58))	//is number				
//			symbol = 1;
//		else if (string[i] == 40)						//is bracket						
//			symbol = 2;
//		else if ((string[i] == 42) ||		//*
//				 (string[i] == 43) ||		//+
//				 (string[i] == 45))			//-
//			symbol = 3;
//		else if (string[i] == 94)			//^
//			symbol = 4;
//		else if (string[i] == 0)
//			break;
//		else
//			symbol = -1;
//		
//		switch (symbol)
//		{
//		case 0:
//			if ((string[i - 1] == 42) ||
//				(string[i - 1] == 43) ||
//				(string[i - 1] == 45) ||
//				(string[i - 1] == 40))
//			{
//				isCorrect = true;
//				if (isBiQuad)
//					if (string[i + 1] != 94)
//					{
//						cout << '\n' << "Mistake: incorrect exponent: " << string[i - 1] << string[i] << string[i + 1];
//						isCorrect = false;
//					}
//			} else {
//				cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
//				isCorrect = false;
//			}
//			break;
//		case 1:
//			if (((string[i - 1] > 47) && 
//				 (string[i - 1] < 58)) || 
//				((string[i - 1] == 42) ||
//				 (string[i - 1] == 43) ||	
//				 (string[i - 1] == 45) ||	
//				 (string[i - 1] == 94) ||
//				 (string[i - 1] == 40) ||
//				 (string[i - 1] == 0)))
//			{
//				isCorrect = true;
//			} else {
//				cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
//				isCorrect = false;
//			}
//			break;
//		case 2:
//			for (int j = i + 1; j < strEnd + 1; j++)
//				if (string[j] == 41)
//				{
//					isExpressionCorrect(i + 1, j - 1, string);
//					i = j + 1;
//					break;
//					isCorrect = true;
//				}
//				else if (j == 150)
//				{
//					cout << '\n' << "Mistake: expected ')'";
//					isCorrect = false;
//				}
//			break;
//		case 3:
//			if ((((string[i - 1] > 47) && (string[i - 1] < 58)) || (string[i - 1] == 120) || (string[i - 1] == 41)) && (string[i + 1] != 0))
//			{
//				isCorrect = true;
//			} else {
//				cout << '\n' << "Mistake: incorrect syntax of operation: " << string[i - 1] << string[i] << string[i + 1];
//				isCorrect = false;
//			}
//			break;
//		case 4:
//			if ((string[i - 1] == 120) && ((string[i + 1] == 50) || (string[i + 1] == 52)))
//			{
//				isCorrect = true;
//				if (string[i + 1] == 52)
//					isBiQuad = true;
//			} else {
//				cout << '\n' << "Mistake: incorrect exponent: " << string[i - 1] << string[i] << string[i + 1];
//				isCorrect = false;
//			}
//			break;
//		case -1:
//			cout << '\n' << "Incorrect input: " << string[i - 1] << string[i] << string[i + 1];
//			isCorrect = false;
//		}
//	}
//	return isCorrect;
//}
//
//int main()
//{
//	char expression[151] = {0};
//	short int symbolcounter = 1, ch = 0;
//		
//	while ((symbolcounter < 151) && (ch != 13) && (ch != 27))
//	{
//		system("cls");
//		cout << "Equation input:" << '\n' << "0=";
//		for (int i = 1; i < 150; i++)
//		{
//			cout << expression[i];
//			if (expression[i + 1] == 0)
//				break;
//		}
//		ch = _getch();
//		if ((ch == 8) && (symbolcounter > 0))
//		{
//			symbolcounter--;
//			expression[symbolcounter] = 0;
//		}
//		if ((ch >= 32) && (ch <= 252))
//		{
//			if (ch != 224)
//			{
//				expression[symbolcounter] = ch;
//				symbolcounter++;
//			}
//			else if (!_getch())
//			{
//				expression[symbolcounter] = ch;
//				symbolcounter++;
//			}
//		}
//	}
//	
//	isExpressionCorrect(1, 150, expression);
//	system("cls");
//	equationOutput(expression);
//	isExpressionCorrect(1, 150, expression);
//	convert(expression);
//	cout << '\n';
//	equationOutput(expression);
//	system("pause");
//	return 0;
//}


#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

bool checkErrors(string formula) {
	return true;
}

string errorMessage(string formula) {
	return "Error somethere here...";
}

bool isSquareEquation(string formula) {
	for (int i = 0; i < formula.size() - 1; i++)
	{
		if (formula[i] == '^' && formula[i + 1] == '4')
		{
			return false;
		}
	}
	return true;
}

int main()
{
	// Получение исходной строки уравнения
	/*
		Уравнение должно быть вида:
		5*x^2+10*x+3=0
		-5*x^2-10*x-3=0
		5*x^4+10*x^2+3=0
	*/
	string equation;
	cout << "Enter your equation: ";
	cin >> equation;
	system("cls");
	if (checkErrors(equation) == true)
	{
		// Тестовый пример. Используется только для отладки - УДАЛИТЬ
		//equation = "2*x^2+3*x+1=0";
		float a, b, c = 0;
		string a_s, b_s, c_s = "";
		int stop = 0;
		// Блок получения коэфициентов уравнения
		for (int i = 0; i < equation.size(); i++)
		{
			if (equation[i] == 'x' && (equation[i + 1] == '^')) {
				for (int j = 0; j < i - 1; j++)
				{
					a_s += equation[j];
				}
				stop = i + 3; //Перемещение коретки на 3 знака вперед (^2)
			}
			else
			{
				if (equation[i] == 'x')
				{
					for (int j = stop; j < i - 1; j++)
					{
						b_s += equation[j];
					}
					stop = i + 1;
				}
				else
				{
					if (equation[i] == '=')
					{
						for (int j = stop; j < i; j++) {
							c_s += equation[j];
						}
					}
				}

			}
		}
		a = atoi(a_s.c_str());
		b = atoi(b_s.c_str());
		c = atoi(c_s.c_str());
		if (isSquareEquation(equation))
		{
			// Получение корней квадратного уравнения
			float D = 0;
			float x1 = 0;
			float x2 = 0;
			D = b * b - 4 * a*c;
			if (D >= 0)
			{
				x1 = (-1 * b + sqrt(D)) / (2 * a);
				x2 = (-1 * b - sqrt(D)) / (2 * a);
			}
			// Отрисовка графика
			float x;
			HDC hDC = GetDC(GetConsoleWindow());
			HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
			SelectObject(hDC, Pen);
			MoveToEx(hDC, 0, 85, NULL);
			LineTo(hDC, 200, 85);
			MoveToEx(hDC, 100, 0, NULL);
			LineTo(hDC, 100, 170);
			for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
			{
				MoveToEx(hDC, 10 * x + 100, a*x*x + b * x + c, 0);//10 - scale
				LineTo(hDC, 10 * x + 100, a*x*x + b * x + c);
			}
			// Вывод корней уравнения
			cout << "x1 = " << x1 << '\n' << "x2 = " << x2 << '\n';
		}
		else
		{
			// Получение корней биквадратного уравнения и его отрисовка
		}

	}
	else
	{
		string error = errorMessage(equation);
		cout << error;
	}
	system("pause");
}