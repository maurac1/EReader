#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{
 public:
  //Name: Book - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default book
  Book();
  //Name: Book - Overloaded Constructor
  //Precondition: Requires title, author, rank and price (in dollars)
  //Postcondition: Creates a book based on passed parameters
  Book(string title, string author, int rank,  double price);

  //Name: Mutators and Accessors
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
  string getTitle()const; // return title
  string getAuthor()const; // return author
  int getRank()const; // return rank (1-150)
  double getPrice()const; // return price 
  void setTitle(string title);
  void setAuthor(string author);
  void setRank(int rank);
  void setPrice(double price);
  // Overloaded << - Prints the details of a book
  // Preconditions: all variables are set valid
  // Postconditions: returns an ostream with details of a book
  friend ostream& operator<<(ostream&, Book&);
  // Overloaded < - compares the price of the book
  // Preconditions: all variables are set valid
  // Postconditions: returns true if lhs price is less than rhs price
  friend bool operator< (Book const & lhs, Book const & rhs);
private:
  string m_title; //Title of book
  string m_author; //Author of book
  int m_rank; //Rank 1-150
  double m_price; //Price in dollars
};

#endif
