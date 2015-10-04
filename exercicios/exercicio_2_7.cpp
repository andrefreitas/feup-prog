// Exercice 2.7
// Problem: Print the sin, cos and tan of angles.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	cout << "ang\t    sen\t      cos\ttan\n";

	for (float i=0; i<= 90; i+=15){
		if(!i) cout << ' '; // Space formating for 0
	cout << (int)i << setw(7) << fixed << setprecision(7) << ' ' << sin(i/180) << ' ' << cos(i/180) << ' ' << tan(i/180) << '\n';
	}

	cout << '\n';
	system("pause");
	return 0;
}