#include <iostream>
#include "library.h"
using namespace std;

IdentNum User::numUsers=0;
// Constructor
User::User(){
	ID=0;
}

User::User(string name){
	numUsers++;
	this->name=name;
	ID=numUsers;
	setActive(true);
}

// Get methods
IdentNum User::getID() const{
	return this->ID;
}

string User::getName() const{
	return this->name;
}

bool User::isActive() const{
	return this->active;
}

vector<IdentNum> User::getRequestedBooks() const{
	return requestedBooks;
}

bool User::hasBooksRequested() const{
	return !requestedBooks.empty();
}

// Set methods
void User::setID(IdentNum userID){
	this->ID=userID;
}

void User::setName (string userName){
	this->name=userName;
}

void User::setActive(bool status){
	this->active=status;
}

void User::setRequestedBooks(const vector <IdentNum> &booksRequestedByUser){
	requestedBooks=booksRequestedByUser;
}

void User::setNumUsers(IdentNum num){
	numUsers=num;
}

void User::borrowBook(IdentNum bookID)
{	vector <IdentNum> books=requestedBooks;
	books.push_back(bookID);
	setRequestedBooks(books);
}

void User::returnBook(IdentNum bookID)
{

	for (unsigned int i=0; i<requestedBooks.size();i++)
	{
		if(requestedBooks[i]==bookID)
			requestedBooks.erase(requestedBooks.begin()+i);
	}
}


//EXTRAS
string User::showStatus() const
{
	if (isActive())
		return "Sim";
	else return "Nao";
}

//return true if the user has the book
bool User::havethebook(IdentNum bID) const
{	
	bool check=false;
	
	if(bID>0){
		for (unsigned int i=0; i<requestedBooks.size();i++){
		if(requestedBooks[i]==bID)
			check=true;
		}
	}
	return check;
}