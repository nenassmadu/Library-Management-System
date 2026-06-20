#ifndef AUTHOR_HPP
#define AUTHOR_HPP
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Book;

class Author {
	string name, idAuthor, biography;
	Book *book;
	int totalBooks;
	
	public :
		Author(string n = "", string id = "", string bio = "");	
		void addBook(Book *);
		void getBook(map<string, Book> &b);
		string getAuthorID() const;
	    string getAuthorName() const;
	    string getBiography() const;
	    void findAuthor(map<string, Book> &b);
		void displayAuthor(map<string, Book> &b);
		~Author();
};

#endif
