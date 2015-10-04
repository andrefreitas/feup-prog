// Exercice 2.15
// Problem: Check if the user know how to multiply
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	// Randomize numbers
	srand(time(NULL));
	int num1=rand()% 8 + 2;
	int num2=rand()% 8 + 2;
	// Result
	int res=num1*num2;
	// Timers
	time_t tinitial,tfinal,delta;

	// Input
	cout << num1 << " x " << num2 << " = ? ";
	tinitial=time(NULL);
	int ans;
	cin >> ans;
	tfinal=time(NULL);
	delta=tfinal-tinitial;

	// Evaluate
	if (ans!=res) cout << "Very Bad!\n";
	else if (delta < 5) cout << "Good!\n";
	else if (delta >=5 && delta <=10) cout << "Reasonable\n";
	else cout <<"Insuficient!\n";

	cin.get();
	system("pause");
}