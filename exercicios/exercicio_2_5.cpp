// Exercice 2.4
// Problem: Calculates the roots of a quadratic function
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	// Read a,b and c
	double a,b,c;
	cout << "Introduza os coeficientes (a b c): ";
	cin >> a >> b >> c;

	// Compute the solution
	double insideRoot;
	insideRoot=(double)b*b-4*a*c;
	double sol[2];
	// Real solution
	if (insideRoot >= 0) {
		sol[0]=(-b+sqrt(insideRoot))/(2*a);
		sol[1]=(-b-sqrt(insideRoot))/(2*a);
		if (sol[0]==sol[1]) cout << "A equacao tem 2 raizes reais iguais: " << sol[0] << '\n';
		else cout << "A equacao tem 2 raizes reais: " << sol[0] << " e " << sol[1] << '\n';}
	// Complex solution
	else {
		double real =-b/(2*a);
		double imaginary= sqrt(-insideRoot)/(2*a);
		cout << "A equacao tem 2 raizes complexas conjugadas: ";
		cout << setprecision (4);
		cout << real << '+' <<  imaginary <<'i' << " e " << real << '-' << imaginary <<"i\n";
	}
	// cout << "SQRT: " << insideRoot << endl;	
	system("pause");
	return 0;
}