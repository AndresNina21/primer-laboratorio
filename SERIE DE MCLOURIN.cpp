// serie de maclaurin

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int fact(int a)
{
	int F = 1;
	for (int i = 1; i <= a; i++)
	{
		F = F*i;
	}
	
	return F;
}

int main()
{
	int n; float an;
	cout <<"---------calculadora de maclaurin---------" <<endl;
	cout << "ingrese el numero de terminos :"; cin >> n;
	cout << "ingrese el valor del angulo :"; cin >> an;
	
	double seno = 0, coseno = 0;
	
	for (int k = 0; k < n; k++)
	{
		seno = seno + pow(-1,k)*pow(an, 2 * k + 1) / fact (2 * k + 1);
		coseno = coseno + pow(-1,k)*pow(an, 2 * k) / fact (2 * k);
	}
	
	cout << "\n el valor de sen("<<an<<") =" << seno << endl;
	cout << "\n el valor de cos("<<an<<") =" << coseno << endl;
	
	_getch();
}
