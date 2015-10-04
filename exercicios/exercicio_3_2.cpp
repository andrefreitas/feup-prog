// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.2
// Problem: Print n prime numbers
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num){
	int lim=(int)sqrt((float)num);
    for (int i=2; i<=lim; i++)
		if ((num % i) == 0) return 0;
	return 1;
}
int main(){
	cout << "First n numbers? ";
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
		if (isPrime(i)) cout << i << endl;
	cin.get();
	return 0;
}