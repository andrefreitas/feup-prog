// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.8
// Problem: Compute the GCD
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
int gcdEuclides(int num1,int num2){
	// num1 is the greatest
	if(num2>num1){
		int aux;
		aux=num1;
		num1=num2;
		num2=aux;}
	// Initialization
	int quotient, remainder;
	quotient=num1/num2;
	remainder=num1%num2;
	int num1Old;
	// Euclids algorithm: num1 = quotient(num1,num2) x num2 + remainder(num1,num2)
	while (remainder!=0){
		// gcd(num1,num2)=gcd(num2,remainder(num1,num2))
		num1Old=num1;
		num1=num2;
		num2=num1Old%num2;
		remainder=num1%num2;
		quotient=num1/num2;
	}
	return num2;
}
int main(){
	int num1,num2;
	cout << "Num1? Num2? ";
	cin >> num1 >> num2;

	cout << "The GCD is; " << gcdEuclides(num1,num2) << endl;
	cin.get();
	return 0;
}