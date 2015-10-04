// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.7
// Problem: Read a vector and search a value
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
// Functions
void readVector(vector<int> &v, int nElem);
int searchValueInVector(const vector<int> &v, int value);
vector<int> searchMultValuesInVector(const vector<int> &v, int value);
// Main
int main(){
	int nelementos;
	cout << "How many elements? ";
	cin >> nelementos;
	vector<int> vec(nelementos);
	// Read elements
	readVector(vec,nelementos);
	// Search Value in Vector
	cout << "Value to search? ";
	int value;
	cin >> value;
	cout << "Position: " << searchValueInVector(vec,value) << endl;
	// Multiple positions:
	vector <int> pos=searchMultValuesInVector(vec,value);
	cout << "Positions: ";
	if (pos[0]==-1) cout << "Not found!\n";
	else {
		for (int i=0;pos[i]!=0;i++)
			cout << pos[i] << " ";
	}
	cin.get();
	return 0;

}
void readVector(vector<int> &v, int nElem){
	for (int i=0; i<nElem;i++){
		cout << "Element n" << i+1 << "? ";
		cin >> v[i];
	}
}
int searchValueInVector(const vector<int> &v, int value){
	for (int i=0; i<v.size();i++)
		if (v[i]==value) return i;
	
	return -1;
}
vector<int> searchMultValuesInVector(const vector<int> &v, int value){
	vector <int> positions(v.size());
	int j=0;
	positions[0]=-1;
	for (int i=0; i<v.size();i++)
		if (v[i]==value){
			positions[j]=i;
			j++;
		}
	positions[j]=0;
	return positions;
}