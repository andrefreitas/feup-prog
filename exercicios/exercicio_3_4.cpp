// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.4
// Problem: Rounds a number
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
using namespace std;
double round(double x,unsigned n);
int main(){
	// Input
	double x;
	unsigned n;
	cout << "Number? ";
	cin >> x;
	cout << "Decimal houses? ";
	cin >> n;
	cout << "Rounded number: " << round(x,n) << endl;
	cin.get();
	return 0;
}
double round(double x,unsigned n){
	return floor((x*pow(10.0,(int)n)+0.5))/pow(10.0,(int)n);
}