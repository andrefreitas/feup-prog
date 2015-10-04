// Exercice 2.2
// Problem: Lê três números e determina o maior e o menor desses números.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Input
	int n[3];
	cout << "a? b? c? ";
	cin >> n[0]>> n[1] >> n[2];

	// Selection Sort
	int min;
	int i=0, j=0,troca=0;
	for (i=0; i<3; i++){ // Main cicle
		min=i;
		for (j=i; j<3; j++){ // Secondary cicle
			if (n[min]> n[j]) min=j;
		}
		troca=n[i];
		n[i]=n[min];
		n[min]=troca;
	}

	// Print the Max and Min
	cout << "Minimum: " << n[0] << '\n';
	cout << "Maximum " << n[2] << '\n';
	system("pause");
	return 0;
}