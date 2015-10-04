// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.4
// Problem: Normalize a string removing extra spaces, to uppercase, and removing " de ", " do ", " da ", " das ", " dos " and " e "
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// Anotations and Recommendations:
// 1) Tolower: transform(st.begin(), st.end(), st.begin(), ::tolower); #include <algorithm>
// 2) Useful string functions: int npos= name.find(" "); name.erase(npos,1); name.replace(npos,1," ");
// 3) Use Deitel Book page 768
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string normalizeName(string name);
void removeSt(string &name,string comp);
int main(){
	cout << "String? ";
	string st;
	getline (cin,st);
	// To lower case to evaluate more easy in "do", "da", etc...
	transform(st.begin(), st.end(), st.begin(), ::tolower);
	cout << "Final String:" << normalizeName(st) << endl;
	cin.get();
	return 0;
}
string normalizeName(string name){
	// Find the correct position for spaces and substitute
	for (int i=0; i<name.length(); i++)
		if ((i+1)< name.length() && name[i]!=' ' && name[i]!='*' && name[i+1]==' ' ) name[i+1]='*';
	
	// Remove all spaces
	int npos= name.find(" ");
	while (npos!=-1){
		name.erase(npos,1);
		npos= name.find(" ");}

	// Replace *
	npos= name.find("*");
	while (npos!=-1){
		name.replace(npos,1," ");
		npos= name.find("*");}

	// NOTE: Must have spaces if not descalço=scalço
	removeSt(name," de ");
	removeSt(name," do ");
	removeSt(name," da ");
	removeSt(name," das ");
	removeSt(name," dos ");
	removeSt(name," e ");

	// To uppercase
	for (int i=0; i < name.length(); i++)
		name[i]=toupper(name[i]);


	return name;
}
void removeSt(string &name,string comp){
	
	int npos= name.find(comp);
	while (npos!=-1){
		name.erase(npos,comp.length());
		npos= name.find(comp);
	}
}