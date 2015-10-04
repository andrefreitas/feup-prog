// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.8
// Problem: Bubblesort
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubblesort(vector <string> &v);
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