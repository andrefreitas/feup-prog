// Exercice 2.8
// Problem: Return que funds after n years with j interest above a n amount
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	// Read data
	cout << "Number of years? ";
	int n;
	cin >> n;
	cout << "First deposit? ";
	float q;
	cin >> q;
	cout << "Interest?(%) ";
	float j;
	cin >> j;

	// Compute and print
	cout << "Amount after " << n << " years: " << q*pow(1+j,n) << endl;
	system("pause");
	return 0;
}