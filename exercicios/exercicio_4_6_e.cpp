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
void MultValuesInArray(const int a[],int nElem,int value, int index[]);
int main(){
	// Declarations
	int nElem;
	int *a = new int[nElem];
    int *index = new int[nElem];
	int value;

	// Input number of elements and read array
    cout << "How many elements?";
	cin >> nElem;
	readArray(a,nElem);

	// Search a value
	cout << "Search value: ";
	cin >> value;
	MultValuesInArray(a,nElem,value,index);

	// See the index
	if (index[0]==-1) cout << "That element doesn't exist!\n";
	else{
		cout << "Positions: ";
	    for (int i=0; index[i]!=-1 && i<nElem; i++)
			cout << index[i] << '\t';
	}
	cout << endl;

	// Delete array
	delete[] a;
	delete[] index;
	cin.get();
	return 0;
}
void readArray(int *a,int nElem){
	for (int i=0; i<nElem; i++){
		cout << "Element n" << i+1 << "? ";
		cin >> *(a+i);
	}
}
void MultValuesInArray(const int a[],int nElem,int value, int index[]){
	int j=0;
	index[0]=-1; // by default
	for (int i=0; i<nElem; i++)
		if (a[i]== value) {
			index[j]=i;
			j++;
		}
		index[j]=-1;
}