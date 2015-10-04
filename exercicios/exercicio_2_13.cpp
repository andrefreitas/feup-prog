// Exercice 2.13
// Problem: Read a number and compose it in prime numbers
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
bool isprime(int n){
	float lim=sqrt((float)n);
	for (int i=2; i<=lim; i++)
		if ((n % i) == 0) return 0;
	return 1;}

int main(){
	// Read the number
	cout << "Number? ";
	int num;
	cin >> num;

	// Prime computing
	int prime[]={2,3,5,7,11,13,17,23,29,31};
	int primeCounter[10]={0.0};
	while (!isprime(num)){
		for (int i=0; i<10;i++)
			if (num%prime[i]==0) {
				primeCounter[i]++;
				num/=prime[i];
				break;
			}
	}
	// Compute the remainder
	for (int i=0; i<10;i++)
			if (num==prime[i]) {
				primeCounter[i]++;
				num=0;
				break;
			}

    // Print the results
	for (int i=0; i<10; i++)
		if (primeCounter[i]!=0) 
			cout << prime[i] << '^' << primeCounter[i] << " * ";
	cout << endl;
	system("pause");
	return 0;

}