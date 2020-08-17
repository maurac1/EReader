// File: Book.cpp
// Author: Maura Choudhary
// Date: 4/23/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the code for the Book class.

#include "Book.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Name: Book - Default Constructor
// Preconditions: None
// Postconditions: Creates a default book
Book::Book(){

}

// Name: Book - Overloaded Constructor
// Preconditions: Requires title, author, rank, and price(
// Postconditions: Creates a book based on passed parameters
Book::Book(string title, string author, int rank, double price){

  m_title = title;
  m_author = author;
  m_rank = rank;
  m_price = price;
}

// Name: Mutators and Accessors
// Preconditions: None
// Postconditions: Sets and Gets private member variables

// get title
string Book::getTitle() const{
  return m_title;
}

// get author
string Book::getAuthor() const{
  return m_author;
}

// get rank
int Book::getRank() const{
  return m_rank;
}

// get price
double Book::getPrice() const{
  return m_price;
}

// set title
void Book::setTitle(string title){
  m_title = title;
}

// set author
void Book::setAuthor(string author){
  m_author = author;
}

// set rank
void Book::setRank(int rank){
  m_rank = rank;
}

// set price
void Book::setPrice(double price){
  m_price = price;
}

// Overloaded << - Prints the details of a book
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with details of a book
ostream& operator<<(ostream& output, Book& myBook){

  // print out formatted Book data
  output << setw(40) << myBook.m_title << setw(25) << myBook.m_author << '\t';
  output.setf(ios::fixed);
  output.setf(ios::showpoint);
  output.precision(2);
  output << "($" << myBook.m_price << ")" << endl;
  return output;
}

// Name: Overloaded < - compares the price of the book
// Preconditions: all variables are set valid
// Postconditions: returns true if lhs price is less than rhs price
bool operator< (Book const & lhs, Book const & rhs){

  // compare book prices
  if(lhs.m_price < rhs.m_price){

    return true;
  }else{
    return false;
  }
}
