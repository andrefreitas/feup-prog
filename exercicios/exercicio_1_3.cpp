// Exercice 1.3 
// Problem: A massa de uma esfera é dada pela expressão  M = 4/3(??r^3)
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#define pi 3.1415927

using namespace std;

int main(){
	// Input
	double p, r, m;
	cout << "Input p (Kg/m^3): ";
	cin >> p;
	cout << "Input r (meters): ";
	cin >> r;
	// Compute
	m = 4.0/3*p*pi*r*r*r;
	// Output
	cout << "Mass of the sphere: " << m << " Kg \n";
	system("pause");


}