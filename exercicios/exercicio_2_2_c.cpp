// Exercice 2.2 c
// Problem: Lê os lados de um triângulo e verificar se os valores podem representar as medidas de um triângulo.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Data input
	cout << "This program read the values of the sides of a triangle\nand evaluates if they are possible.\n\n";
	cout << "Introduze the three sides (double): ";
	double side[3];
	cin >> side[0] >> side[1] >> side[2];

	// Selection Sort
	int menor; double aux;
	for (int i=0; i<3;i++){
		menor=i;
		for (int j=i; j<3; j++)
			if (side[j]<side[menor]) menor=j;
			aux=side[i];
			side[i]=side[menor];
			side[menor]=aux;
	}

	// Evaluate the ordered sides
	if ((side[0]+side[1])>side[2]) cout << "The triangle is possible!\n";
	else cout << "The triangle is IMPOSSIBLE :(\n";

	system("pause");
	return 0;
}