// Exercice 2.11
// Problem: Serie that aproximate PI Number
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	// Read the n value
	cout << "This program aproximates the PI number\nPlease insert n: ";
	int n;
	cin >> n;

	// Compute the sum of the first n terms
	float sum=4;
	for (int i=1;i<=n; i++) 
	sum+=pow(-1.0,i)*(4.0/(2*i+1));

	// Print the sum
	cout << "Sum: " << sum << endl;

	system("pause");
	return 0;
}