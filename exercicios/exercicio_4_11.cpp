// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.11
// Problem: Intersect and unit vector
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Functions
void bubblesort(vector <int> &v);
int binarySearch(const vector<int> &v,int value);
void removeDuplicates(vector<int> &v);
vector<int> vunion(vector<int> v1,vector<int> v2);
void printvector(vector <int> &v);
void fillvector(vector <int> &v);
vector<int> vintersect(vector<int> v1,vector<int> v2);
// Main
int main(){
	vector <int> vec1(10);
	vector <int> vec2(10);
	vector <int> unionvec(20);
	vector <int> intersectvec(20);
	// Fill and print vectors
	fillvector(vec1);
	fillvector(vec2);
	cout << "Vector1: \n";
	printvector(vec1);
	cout << "\nVector2: \n";
	printvector(vec2);
	// Union of vectors
	cout << "\nUnion: \n";
	unionvec=vunion(vec1,vec2);
	printvector(unionvec);
	// Intersect vectors
	cout << "\nIntersect: \n";
	intersectvec=vintersect(vec1,vec2);
	printvector(intersectvec);
	cin.get();
	return 0;
}
// ************************************
//       Print vector
// ************************************
void printvector(vector <int> &v){
	for (unsigned int i=0; i<v.size();i++)
		cout << v[i] << ' ';
}

// ************************************
//       Print vector
// ************************************
void fillvector(vector <int> &v){
	for (unsigned int i=0; i<v.size();i++)
		v[i]=rand() % 10 +1;
}

// ************************************
//       Bubblesort function
// ************************************
void bubblesort(vector <int> &v){
bool flag=0;
int aux;
 do{
	 flag=0;
	 for (int unsigned i=0; i<v.size();i++){
		if ((i+1)<v.size() && v[i]>v[i+1]){
			aux=v[i];
			v[i]=v[i+1];
			v[i+1]=aux;
			flag=1;
		}
	 }
 }while(flag);
}
// ************************************
//       Binary search
// ************************************
int binarySearch(const vector<int> &v,int value){
	for (int unsigned i=0; i<v.size();i++){
		if (v[i]==value) return i;
		if (v[i]>value || i==v.size()-1) return -1;}
	return -1;
	
}
// ************************************
//    Remove duplicates and resize
// ************************************
void removeDuplicates(vector<int> &v){
	vector <int> control(v.size(),0);
	// If not exists, copy to control
	int j=0;
	for (unsigned int i=0; i<v.size();i++){
		if (binarySearch(control,v[i])==-1){
			control[j]=v[i];
			j++;}}
	// cont how many are not zero
	int counter=0;
	for (unsigned int i=0; i<v.size();i++)
		if (control[i]) counter++;
	control.resize(counter);
	v.resize(counter);
	v=control;
}
// ************************************
//       Union of two vectors
// ************************************
vector<int> vunion(vector<int> v1,vector<int> v2){
	vector<int> final(v1.size()+v2.size());
	for (unsigned int i=0; i<v1.size(); i++)
		final[i]=v1[i];
    int j=0;
	for (unsigned int i=v1.size(); i<final.size(); i++){
		final[i]=v2[j];
	    j++;
	}
	bubblesort(final);
	removeDuplicates(final);
	return final;
}
// ************************************
//       Intersect of two vectors
// ************************************
vector<int> vintersect(vector<int> v1,vector<int> v2){
	vector<int> final(v1.size());
	bubblesort(v1);
	bubblesort(v2);
	unsigned int j=0;
	for (unsigned int i=0;i<final.size(); i++){
		if (binarySearch(v2,v1[i])!=-1){
			final[j]=v1[i];
			j++;
		}
	}

	bubblesort(final); 
	removeDuplicates(final);
	return final;
}