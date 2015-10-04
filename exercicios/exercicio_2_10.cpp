// Exercice 2.10
// Problem: Check if the backwards of a integer of 3 digits is the same as the original integer
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Read the number
	int num;
	cout << "Number? ";
	cin >> num;
	
	// Compute the backwards
	int backw;
	backw=100*(num%10); //a00
	num/=10; // remove last digit
	backw+=10*(num%10); //ab0
	num/=10; // remove last digit
	backw+=(num%10); //abc

	// Check if they are equal
	if (backw==num) cout << "The integer is palindrome!\n";
	else cout << "The integer isn't palindrome\n";
	system("pause");
	return 0;
}