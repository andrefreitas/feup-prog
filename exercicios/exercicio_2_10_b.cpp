// Exercice 2.10
// Problem: Check if the backwards of a integer of 3 digits is the same as the original integer
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
int lengthof(int n){
	int i=0;
	while (n){
		n/=10;
		i++;}
	return i;
}
int main(){
	// Read the number
	int num;
	cout << "Number? ";
	cin >> num;
	int aux; // Unless the aux exists, the comparizon it's bugged

	// Compute the length and backwards
    int  length=lengthof(num);
	int backw=0;
	aux = num;
	for (int i=length; i>=1; i--){
		backw+=(int)(aux%10)*pow(10.0,i-1); // Floats the point
		aux/=10;
	}

	// Check if they are equal
	if (backw==num) cout << "\nThe integer is palindrome!\n";
	else cout << "\nThe integer isn't palindrome\n";

	system("pause");
	return 0;
}