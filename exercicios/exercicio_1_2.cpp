// Exercice 1.2 
// Problem: Escreva um programa que leia do teclado 3 n�meros inteiros 
// e apresente no ecr� a sua m�dia e a diferen�a de cada um dos n�meros em rela��o � m�dia
// Author: Andr� Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int a, b, c;
	float media;
	// Read A, B e C
	cout << "A ? ";
	cin >> a;
	cout << "B ? ";
	cin >> b;
	cout << "C ? ";
	cin >> c;
	media=(float)(a+b+c)/3;
	// Print the results
	cout << setprecision(5); // Define decimal precision
	cout << "media   = " << media<< '\n';
	cout << "A-media  = " <<a-media << '\n';
	cout << "B-media  = " <<b-media << '\n';
	cout << "C-media  = " <<c-media << '\n';
	system("pause");

}