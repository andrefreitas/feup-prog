// Exercice 2.6 a
// Problem: Evaluates if the number is prime
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	// Read the number
	cout << "Enter a number: ";
	int n; 
	cin >> n;

	// Check if the remainder is 0 until sqrt(n)
	float lim=sqrt((float)n);
	for (int i=2; i<=lim; i++)
		if ((n % i) == 0){ cout << "The number isn't prime!\n"; 
						system("pause"); 
						return 0;}
	cout << "The number is prime!\n";
	system("pause"); 
	return 0;
}