// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.6
// Problem: 
// Author: André Freitas 
// Anotattions: 
// 1) Redim arrays: First int *a = new int[nElem]; and then delete[] a;
// 2) Calling functions by pointers: function(array) -> void function(int *array). & not necessary on call
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
void readArray(int a[],int nElem);
int searchValueInArray(const int a[],int nElem,int value);
int main(){
	int nElem;
    cout << "How many elements?";
	cin >> nElem;
	// Redim array
	int *a = new int[nElem];
	readArray(a,nElem);
	cout << "Search value: ";
	int value;
	cin >> value;
	cout << "Position: " << searchValueInArray(a,nElem,value) << endl; 
	// Delete array
	delete[] a;
	cin.get();
	return 0;
}
void readArray(int *a,int nElem){
	for (int i=0; i<nElem; i++){
		cout << "Element n" << i+1 << "? ";
		cin >> *(a+i);
	}
}
int searchValueInArray(const int a[],int nElem,int value){
	for (int i=0; i<nElem; i++)
		if (a[i]== value) return i;
	return -1;
}