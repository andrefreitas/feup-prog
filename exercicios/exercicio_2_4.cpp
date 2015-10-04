// Exercice 2.4
// Problem: Calculate the transportation price in function of the weight
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Read the weight
	cout << "Calculate the transportation price in function of the weight\nWeight(Kg): ";
	int weight;
	cin >> weight;

	// Compute the cost
	cout << "The cost is ";
	if (weight < 500) cout << "5\n";
	else if (weight>=500 && weight<=1000) cout << 5 + ((weight-500)/100)*1.5 << '\n';
	else cout << 12.5+ ((weight-1000)/250)*5 << '\n';

	system("pause");
	return 0;
}