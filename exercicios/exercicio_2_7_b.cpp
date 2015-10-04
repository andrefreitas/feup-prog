// Exercice 2.7 b
// Problem: Print the sin, cos and tan of angles.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
#include <iomanip>
#define START 0
#define END 10
#define INCREMENT 0.1
using namespace std;
int main(){
	cout << "ang\t    sen\t      cos\ttan\n";

	for (float i=START; i<= END; i+=INCREMENT)
	cout << fixed << setprecision(2) << i << setw(7) << fixed << setprecision(7) << ' ' << sin(i/180) << ' ' << cos(i/180) << ' ' << tan(i/180) << '\n';
	

	cout << '\n';
	system("pause");
	return 0;
}