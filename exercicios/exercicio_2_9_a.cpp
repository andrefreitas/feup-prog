// Exercice 2.9 a
// Problem: Read n values and comput the sum, greatest, smaller and average
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	// Initial values
	int greatest=0;
	int smaller=0;
	int sum=0;
	float average;
	int num;
	int i=0;

	// Read input while different from 0
	do {
		cout << "Number? ";
		cin >> num;
		// Compute the greatest, smaller, sum and increment i
		if (num){
			if(num > greatest || i==0) greatest=num;
			if (num < smaller || i==0 ) smaller=num;
			sum+=num;
			i++;
		}
	} while(num);

	// Print the results
	average=(float)sum/i;
	cout << "\nGreatest: " << greatest << endl;
	cout << "Smaller: " << smaller << endl;
	cout << "Sum: " << sum << endl;
	cout << "Average: " << setprecision(3) << average << endl;
	cout << "Total of input: " << i << endl;

	system("pause");
	return 0;
}