// Exercice 2.6 b
// Problem: Print the first 100 prime numbers
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
#define LIMIT 10000
using namespace std;
// Prime function
bool prime(int n){
	float lim=sqrt((float)n);
	for (int i=2; i<=lim; i++)
		if ((n % i) == 0) return 0;
	return 1;}

int main(){

	for (int i=1; i <LIMIT; i++)
		if (prime(i)) cout << i << endl;

	system("pause");
	return 0;

}