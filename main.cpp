#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <ctype.h>


using namespace std;

double number()
{
	double res = 0.00;
	bool a = true;
	int point = 0;

	for(;;)
	{
		char c = cin.get();

		if (c >= '0' && c <= '9')
		{
			res = res * 10 + (c - '0');
			if (point > 0)
			{
				point++;
			}
		}
		else if (c == ' ')
			continue;
		else if ((c == '.') || (c == ','))
		{
			if (point > 0)
			{
				cout << "Некорректный ввод, строка содержит недопустимое значение: точка или запятая";
				exit(-1);
			}
			else
			{
				point++;
			}
		}


		else if (isalpha(c))
		{
			string error = "Некорректный ввод, строка содержит недопустимое выражение ";
			cout << "Некорректный ввод, строка содержит недопустимое выражение ";

			while (a != false)
			{
				if (c == '\n')
				{
					exit(-1);
				}


				else
				{
					if ((c >= '0' && c <= '9') || (c == '+') || (c == '-') || (c == '*') || (c == '/') )
					{
						c = cin.peek();
						c = cin.get();
					}
					else
					{
						cout << c;
						c = cin.peek();
						c = cin.get();
					}

				}
			}
			exit(-1);
		}
		else
		{

			if (point > 0)
			{
				res = res / pow(10,point - 1);
			}


			cin.putback(c);
			return res;
		}
	}
}

double expr();

double skobki()
{
	char c = cin.get();
	if (c == '(')
	{
		double x = expr();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(c);
		return number();
	}
}

double factor()
{
	double x = skobki();

	for (;;)
	{
		char c = cin.get();
		switch(c)
		{
			case '*':
			x *= skobki();
			break;

			case '/':

			double buf;
			buf = skobki();

			if (buf == 0)
			{
				cout << "Деление на ноль нельзя";
				exit(-1);
			}
			x /= buf;
			break;



			default:
			cin.putback(c);
			return x;
		}

	}
}


double expr()
{
	double x = factor();
	for (;;)
	{
		char c = cin.get();

		switch(c)
		{
			case '+':
			x += factor();
			break;

			case '-':
			x -= factor();
			break;

			default:
			cin.putback(c);
			return x;
		}

	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите выражение: " << endl;
	double res = expr();


	cout << fixed << setprecision(2) << res << endl;

	//char otvet;

	cout << "Ввести новое выражение:y\n" << endl;
	res = expr();

	cout << res;

}
