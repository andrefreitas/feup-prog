// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.9
// Problem: Bubblesort with binary search
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubblesort(vector <string> &v);
int binarySearch(const vector<string> &v,string value);
int main(){
	const int stlength=10;
	vector <string> nomes(stlength);
	nomes[0]="Fabia";
	nomes[1]="Helena";
	nomes[2]="Luciana";
	nomes[3]="Carla";
	nomes[4]="Maria";
	nomes[5]="Laura";
	nomes[6]="Bianca";
	nomes[7]="Beatriz";
	nomes[8]="Ana";
	nomes[9]="Anabela";
	// Sort vector
	bubblesort(nomes);
	// Print vector
	for (int i=0; i<stlength;i++)
		cout << nomes[i] << endl;
	// Binary search
	cout << "Name to binary search? ";
	string name;
	cin >> name;
	if(binarySearch(nomes,name)==-1) cout << "Not found!\n";
	else cout << "Position: " << binarySearch(nomes,name) << endl;
		cin.get();
	return 0;
}
void bubblesort(vector <string> &v){
 bool flag=0;
 string aux;
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
int binarySearch(const vector<string> &v,string value){
	for (int i=0; i<v.size();i++){
		if (v[i]>value) return -1;
		if (v[i]==value) return i;
	 }
	
}