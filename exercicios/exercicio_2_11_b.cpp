// Exercice 2.11 b
// Problem: Print the euler number series
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
int fact(int n){
	int prod=1;
	for (int i=1; i<=n; i++)
		prod*=i;
	return prod;
}
int main(){
	// Read the n value
	cout << "This program aproximates the e number\nPlease insert n: ";
	int n;
	cin >> n;

	// Compute the sum of the first n terms
	double sum=1;
	int divisor=0;
	for (int i=1;i<=n; i++) {
		divisor=fact(i);
	    sum+=1.0/divisor;
	}

	// Print the sum
	cout << "Sum: " << sum << endl;

	system("pause");
	return 0;
}