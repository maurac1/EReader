// File: EReader.cpp
// Author: Maura Choudhary
// Date: 4/23/19
// Section: 4
// E-mail: maurac1@umbc.edu
// Description: This is the code for the EReader class.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Book.h"
#include "EReader.h"

using namespace std;

// Menu Constants
const int DISPLAY_BOOKS = 1;
const int ADD_BOOK = 2;
const int DISPLAY_READLIST = 3;
const int SORT_READLIST = 4;
const int QUIT = 5;

// Name: EReader - Default Constructor
// Preconditions: None
// Postconditions: Creates a new EReader
EReader::EReader(){
  
}

// Name: EReader - Overloaded Constructor
// Preconditions: None
// Postconditions: Creates a new EReader and passes the book filename
EReader::EReader(string filename){
  LoadCatalog(filename);
  cout << "Catalog populated with " << m_bookCatalog.size() << " books." << endl;
}

// Name: ~EReader - Destructor
// Preconditions: None
// Postconditions: Creates a new EReader
EReader::~EReader(){
  // look through book list and deallocate books
  for (unsigned int i = 0; i < m_bookCatalog.size(); i++){
    delete m_bookCatalog.at(i);
  }
}

// Name: LoadCatalog(string filename)
// Preconditions: Requires filename
// Postconditions: Manages the application and the menu
void EReader:: LoadCatalog(string filename){

  // define necessary variables
  string title;
  string author;
  string sRank;
  string sPrice;

  // loop through the file
  ifstream myFile(filename);
  if(myFile.is_open()){

    while(!myFile.eof()){
      getline(myFile, title, ',');
      getline(myFile, author, ',');
      getline(myFile, sRank, ',');
      getline(myFile, sPrice, '\n');

      // convert strings to appropriate variables
      int rank = stoi(sRank);
      double price = stod(sPrice);

      // create a new Book using data from file
      if(title != ""){
	Book* newBook = new Book(title, author, rank, price);
	m_bookCatalog.push_back(newBook);
      }
    }

  }
  myFile.close();
}

// Name: MainMenu
// Preconditions: None
// Postconditions: Manages the application and the menu
void EReader::MainMenu(){
  int userInput;
  // get user input and execute menu options
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Books" << endl;;
    cout << "2. Add Book to Readlist" << endl;
    cout << "3. Display Readlist" << endl;
    cout << "4. Sort Readlist by Price" << endl;
    cout << "5. Quit" << endl;
    cin >> userInput;

    switch(userInput){
    case DISPLAY_BOOKS:
      DisplayBooks();
      break;
    case ADD_BOOK:
      AddBook();
      break;
    case DISPLAY_READLIST:
      DisplayReadlist();
      break;
    case SORT_READLIST:
      SortReadlist();
      break;
    case QUIT:
      cout << "Goodbye!" << endl;
      break;
    default:
      cout << "Please enter a valid number." << endl;
      break;
    }

  }while(userInput != QUIT);
}

// Name: DisplayBooks
// Preconditions: Displays all 150 books
// Postconditions: Lists all books (numbered)
void EReader::DisplayBooks(){

  // loop through a print out book catalog
  for(unsigned int i = 0; i < m_bookCatalog.size(); i++){
    cout << (i + 1) << ".";
    cout << *m_bookCatalog.at(i);
  }
}

// Name: AddBook
// Preconditions: m_bookCatalog is populated
// Postconditions: Displays the current list and adds a book
//                 to the m_readList
void EReader::AddBook(){

  // display all books to add
  DisplayBooks();
  cout << "Which book would you like to add?" << endl;
  int userInput;
  cin >> userInput;
  int size = int(m_bookCatalog.size());

  // validate user input
  while((userInput < 1) or (userInput > size)){
    cout << "Not a valid choice, please try again." << endl;
    cin >> userInput;
  }

  // add appropriate book to the readList
  m_readList.Push(*m_bookCatalog.at(userInput - 1), true);
}

// Name: DisplayReadlist
// Preconditions: None (can be empty)
// Postconditions: Displays the readlist
void EReader::DisplayReadlist(){

  // loop through and display books in the readList
  for(int i = 0; i < m_readList.GetSize(); i++){
    cout << (i + 1) << ".";
    cout << m_readList[i];
  }
  
}

// Name: SortReadlist()
// Preconditions: Requires Readlist
// Postconditions: Uses the overloaded < operator in Book to sort
//                 the prices from high to low in the m_readList

void EReader::SortReadlist(){

  // if there are enough elements in the list to be sorted
  if(m_readList.GetSize() >= 2){

    // loop through and sort the books by price
    int i, j;
    for(i = 0; i < m_readList.GetSize() - 1; i++){
      for(j = 0; j < m_readList.GetSize() - i - 1; j++){

	// get book variables
	Book book1, book2;
	book1 = m_readList[j];
	book2 = m_readList[j + 1];

	// test if the second book is more expensive than the first
	if(book2 < book1){
	  m_readList.Swap(j + 1);
	}
      }
    }
  }else{
    cout << "Read list doesn't have enough elements to sort." << endl;
  }
}
