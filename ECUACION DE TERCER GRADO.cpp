// ecuaciones de tercer grado

#include<iostream>
#include <conio.h>
#include <math.h>
using namespace std;

double rcu (double E) { //funcion raiz cubica
// calculo por el metodo de tablas exponenciales y logaritmicas
// formula exp(ln(E)/3)
double raiz;
if (E> 0) { // el logaritmo natural puede calculaa E>0
raiz = exp(log(E)/3);
};
if (E== 0){ // el logaritmo natural no puede calcular E=0
raiz = 0;
};
if (E<0) {
raiz =-exp(log(-E)/3); // el logaritmo natural no calcula E < 0
// es necesario poner el signo "-" a E
};
return raiz;
};

int main(){
double A,B,C,D; // variables de la ecuacion principal
double a1,b1,c1;
double p,q,dis; // variables de la ecuacion reducida
double u,v;
double x,y,z; // valores de las raices
double pi,t; // pi y margen de error

cout<<" Ecuacion cubica de la forma AX^3 + BX^2 + CX + D"<<endl;
cout<<" Introduzca "<<endl;
cout<<" A :"; cin>> A;
cout<<" B :"; cin>> B;
cout<<" C :"; cin>> C;
cout<<" D :"; cin>> D;

cout.precision(3); // muestra la cantidad de decimales deseada
t = 0.0000000009; // tolerancia o margen de error
pi = 3.141592654; // el numero pi
a1 = B/A;
b1 = C/A;
c1 = D/A;
p = b1 - (a1*a1)/3; // variable p del metodo
q = (2*a1*a1*a1)/27 - (a1*b1)/3 + c1; // variable q del metodo
dis = (q*q) + (4*p*p*p)/27; // discriminante
cout<< " Ecuacion reducida : Z^3 + "<<p<< " Z + "<<q<<endl;
cout<< " El discriminante es "<<dis<<endl;


if ( dis >= t ) { //discriminante > 0
u = rcu(0.5*(-q + sqrt(dis))); // variable u del metodo de cardano
v = rcu(-0.5*(q + sqrt(dis))); // variable v del metodo de cardano
x = u + v -(a1/3);
y = (-0.5)*(u+v) -(a1/3);
z = (0.5)*sqrt(3)*(u-v);
cout<<" La ecuacion tiene una raiz real y 2 complejas "<<endl;
cout<<" X1 :"<<x<<endl;
cout<<" X2 :"<<y<<" + "<<fabs(z)<<"i"<<endl;
cout<<" X3 :"<<y<<" - "<<fabs(z)<<"i"<<endl;
};


if ((dis < t and dis > -t) and (p>=-t and p<=t)){ //discriminante= p = 0
cout<<" La ecuacion tiene una sola raiz"<<endl;
cout<<" X :"<<-(a1/3);
};


if ((dis < t and dis > -t) and (p>=t or p<=-t)){ // discriminante = 0
u = rcu(-0.5*q); // no es necesario calcular v, ya que u=v
x = 2*u -(a1/3);
y = -u -(a1/3);
cout<<" La ecuacion tiene raices multiples"<<endl;
cout<<" X1 :"<<x<<endl;
cout<<" X2=X3 :"<<y<<endl;
};


if ( dis <= -t ) { // discriminate < 0
x = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt(-27/(p*p*p)))/3) -(a1/3);
y = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +2*pi/3) -(a1/3);
z = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +4*pi/3) -(a1/3);
cout<<" La ecuacion tiene 3 raices distintas "<<endl;
cout<<" X1 :"<<x<<endl;
cout<<" X2 :"<<y<<endl;
cout<<" X3 :"<<z<<endl;
};


getch(); // Hace una pausa al programa
return 0;
} //fin del programa
