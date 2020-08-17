#include <iostream>
#include "EReader.h"
#include "Book.h"

int main (int argc, char* argv[]) {
  string bookFile;
  cout << "Welcome to UMBC E-Reader"<<endl;
  if(argc > 1){
    bookFile = argv[1];
  } else{
    cout << "One book files required - try again" << endl;
    cout << "./proj5 p5_book.txt" << endl;
    return 0;
  }
  EReader* myReader = new EReader(bookFile);
  myReader->MainMenu();
  delete myReader;
  return 0;
}
