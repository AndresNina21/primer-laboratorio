// Serie de Taylor
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

double taylor(int x, int n);
double factorial(int n);

int main() {
	int n, x;
	cout << "-----calculadora de series de Taylor-----" <<endl;
	cout << "introduce el valor de n=", cin >> n;
	cout << "introduce el valor de x=", cin >> x;
	cout <<	"cuando n="<<n<<" y  x=" <<x<<"  f(x)=" << taylor (x, n) <<endl;
	system ("pause");
}

double taylor  (int x, int n) {
	double t, s = 0;
	int sig = 1;
	for(int i = 0; i < n; i++) {
		t = pow(x, i) / factorial(i) * sig;
		s += t;
		sig *= -1;
	}
	return s;
}

double factorial(int n) {
	double fac = 1;
	for(int i = 2; i <= n; i++) {
		fac *= i;
	}
	return fac;
}
