// Exercice 2.9 n
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
	int length;
	int i;
	
	// Read the numbers length
	cout << "Length? ";
	cin >> length;
	// Read input while number<= length
	for (i=1; i<=length; i++){
		cout << "Number? ";
		cin >> num;
		// Compute the greatest, smaller, sum and increment i
		if(num > greatest || i==1) greatest=num;
		if (num < smaller || i==1 ) smaller=num;
		sum+=num;
	} 
	i--;
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