// Exercice 2.1 
// Problem: Apresentar a solução de um sistema linear, indicado quando se aplica se é impossível ou
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Input
	cout << "Introduza todos os parametros do sistema:\n";
	cout << "a? b? c?: ";
	int a, b, c;
	cin >> a >> b >> c;
	cout << "d? e? f?: ";
	int d, e, f;
	cin >> d >> e >> f;

	// Compute the determinant
	int det;
	det=((a*e)-(d*b));
	
	//Evaluate the determinant
	double x,y;
	if (det == 0) cout << "sistema impossivel\n"; else
		if (det < 0)  cout << "sistema indeterminado\n"; else 
		{x=(double)(c*e-b*f)/(a*e-b*d);
		y=(double)(a*f-c*d)/(a*e-b*d);
		// Print the solutions
		cout << "x= " << x;
		cout << "\ny= " << y << '\n';}
		

	system("pause");
	return 0;
}