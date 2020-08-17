#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
#include "Lqueue.h"

using namespace std;
#ifndef EREADER_H
#define EREADER_H

class EReader{
 public:
  //Name: EReader - Default Constructor
  //Precondition: None
  //Postcondition: Creates a new EReader
  EReader();
  //Name: EReader - Overloaded Constructor
  //Precondition: None
  //Postcondition: Creates a new EReader and passes the book filename
  EReader(string filename);
  //Name: ~EReader - Destructor
  //Precondition: None
  //Postcondition: Creates a new EReader
  ~EReader();
  //Name: LoadCatalog(string filename)
  //Precondition: Requires filename
  //Postcondition: Loads the file into the m_bookCatalog (as books)
  void LoadCatalog(string filename);
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the application and the menu
  void MainMenu();
  //Name: DisplayBooks
  //Precondition: Displays all 150 books
  //Postcondition: Lists all books (numbered)
  void DisplayBooks();
  //Name: AddBook
  //Precondition: m_bookCatalog is populated
  //Postcondition: Displays the current list and adds a book
  //               to the m_readList
  void AddBook();
  //Name: DisplayReadlist
  //Precondition: None (can be empty)
  //Postcondition: Displays the readlist
  void DisplayReadlist();
  //Name: SortReadlist()
  //Precondition: Requires Readlist
  //Postcondition: Uses the overloaded < operator in Book to sort
  //               the prices from high to low in the m_readList
  void SortReadlist();
private:
  vector<Book*> m_bookCatalog; //Holds all books in file
  Lqueue<Book> m_readList; //Holds all books in read list
};

#endif
