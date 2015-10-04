#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include <fstream>
#include "defs.h"
#include "book.h"
#include "user.h"
#include <iostream>
#include <iomanip> //setw
#include <cctype> //toupper
using namespace std;

class Library {

private:
	vector<User> users; // all users that are registered or were registered in the library
	vector<Book> books; // all books that are registered or were registered in the library
	string filenameUsers; // name of the file where users are saved at the end of each program run
	string filenameBooks; // name of the file where books are saved at the end of each program run
public:
	int test;
	// constructors/destructor
	Library();
	Library(string fileUsers, string fileBooks);
	~Library();

	// get functions
	User getUserByID(IdentNum userID) const;
	Book getBookByID(IdentNum bookID) const;

	// user management
	void addUser(User userLib);

	// book management
	void addBook(Book bookLib);

	// loaning management
	void loanBook(IdentNum, IdentNum);
	void returnBook(IdentNum, IdentNum);

	// file management methods
	void loadUsers();
	void loadBooks();
	void saveUsers();
	void saveBooks();

	// information display
	void showUsers() const;
	void showUsers(string str) const;
	void showBooks() const;
	void showBooks(string str) const;
	void showAvailableBooks(User user) const;
	
	// extras
	void showUserBooks(IdentNum uID) const;
	void showActiveUsers() const;
	IdentNum getNumUsers() const;
	IdentNum getNumBooks() const;
	void replaceUser(User user);
	void replaceBook(Book book);
	bool activeUsers() const;
	bool AvailableBooks(User user) const;
};
	// extra FUNCTION. REQUIRED by library.cpp but not a member of the class
	void strToUpper(string &str);

#endif
