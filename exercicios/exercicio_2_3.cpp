// Exercice 2.3
// Problem: Calculator that reads: operand1 (operator) operand2. The operation can be * / + -
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Input
	cout << "Calculator: ";
	double n1,n2; char op; // Operand 1, 2 and Operation
	cin >> n1 >> op >> n2;

	// Compute the operation if valid
	switch(op){
	case '+': cout << n1 + n2 << endl; break;
	case '-': cout << n1 - n2 << endl; break;
	case '*': cout << n1 * n2 << endl; break;
	case '/': cout << n1 / n2 << endl; break;
	default: cout << "\nINVALID OPERATION!!\n\n";
	}

	system("pause");
	return 0;
}