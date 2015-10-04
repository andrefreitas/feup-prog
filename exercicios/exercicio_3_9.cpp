// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.9
// Problem: Compute the numerical integral
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
using namespace std;
double f(double x) {return x*x;}
double h(double x) {return sqrt(4-x*x);}

double integrateTR(double f(double),double a,double b,int n);
int main(){
	int a,b,n;
	cout << "a? b? n? ";
	cin >> a >> b >> n;
	cout << "Integral f(x)=x^2: " << integrateTR(f,a,b,n) << endl;
	cout << "Integral h(x)=sqrt(4-x^2): " << integrateTR(h,a,b,n) << endl;
	cin.get();
	return 0;
}
double integrateTR(double f(double),double a,double b,int n)
{
	double h=(double)(b-a)/n;
	double sum=0;
	for (int i=1; i<=n;i++){
		sum+= h/2.0 * (f(a+(i-1)*h) + f(a+i*h));
	}
	return sum;
}