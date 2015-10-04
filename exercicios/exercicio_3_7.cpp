// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.7
// Problem: Rounds a number
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <climits>
using namespace std;
long factorial_ite(int n);
long factorial_rec(int n);
int main(){
	// Input
	int num;
	cout << "Number? ";
	cin >> num;
	// Compute
	long factorial;
	factorial=factorial_ite(num);
	// Output
	cout << "\nFactorial iterativo: " << factorial << endl;
	cout << "Factorial recursivo: " << factorial_rec(num) << endl;
	/* Compute the max
	long i,fact=1;
	long abs=1;
    for (i=0; abs<LONG_MAX;i++){
		fact=factorial_ite(i);
		if (fact <0) abs=-1*fact; else abs=fact;
		if (fact<=0) break;
	}
	cout << "Max number: " << i-- << endl;
	MAX = 16
	*/
	
	cin.get();
	return 0;
}
long factorial_ite(int n){
	if (n>16) {cout << "INVALID NUMBER!"; return 0;}
	if (!n) return 1;
	long prod=1;
	for (int i=n; i>0;i--)
		prod*=i;
	return prod;
}
long factorial_rec(int n){
	if (!n) return 1;
	else return n*factorial_rec(n-1);
}
