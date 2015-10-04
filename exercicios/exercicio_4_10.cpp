// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.10
// Problem: Bubblesort with binary search and remove duplicates
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubblesort(vector <int> &v);
int binarySearch(const vector<int> &v,int value);
void removeDuplicates(vector<int> &v);
int main(){
	const int stlength=10;
	vector <int> vec(stlength);
	vec[0]=10;
	vec[1]=9;
	vec[2]=8;
	vec[3]=7;
	vec[4]=7;
	vec[5]=7;
	vec[6]=4;
	vec[7]=3;
	vec[8]=2;
	vec[9]=1;
	
	// Sort vector
	bubblesort(vec);
	// Remove Duplicates
	removeDuplicates(vec);
	cout << "\nVector:\n";
	for (int i=0; i<vec.size(); i++){
		cout << vec[i] << ' ';
	}
	cin.get();
	return 0;
}
void bubblesort(vector <int> &v){
 bool flag=0;
int aux;
 do{
	 flag=0;
	 for (int i=0; i<v.size();i++){
		if ((i+1)<v.size() && v[i]>v[i+1]){
			aux=v[i];
			v[i]=v[i+1];
			v[i+1]=aux;
			flag=1;
		}
	 }
 }while(flag);
}
int binarySearch(const vector<int> &v,int value){
	for (int i=0; i<v.size();i++){
		if (v[i]==value) return i;
		if (v[i]>value || i==v.size()-1) return -1;
	 }
	
}
void removeDuplicates(vector<int> &v){
	vector <int> control(v.size(),0);
	// if not exists copy to control
	cout << "Control before: \n";
	int counter=0;
	for (int i=0; i<v.size();i++){
		cout << control[i] << ' ';
		if (control[i]) counter++;
	}
	// If not exists, copy to control
	int j=0;
	for (int i=0; i<v.size();i++){
		if (binarySearch(control,v[i])==-1){
			control[j]=v[i];
			j++;
		}
	}
	// cont how many are not zero
	counter=0;
	cout << "\nControl after: \n";
	for (int i=0; i<v.size();i++){
		cout << control[i] << ' ';
		if (control[i]) counter++;
	}
	control.resize(counter);
	v.resize(counter);
	v=control;

	cout << "\nControl after resize: \n";
	for (int i=0; i<v.size();i++){
		cout << control[i] << ' ';
	}


}