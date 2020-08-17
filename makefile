CXX = g++
CXXFLAGS = -Wall -g

proj5: EReader.o Book.o driver.cpp Lqueue.h
	$(CXX) $(CXXFLAGS) EReader.o Book.o Lqueue.h driver.cpp -o proj5

EReader.o: EReader.cpp  EReader.h Book.o Lqueue.h
	$(CXX) $(CXXFLAGS) -c EReader.cpp

Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c Book.cpp

run:
	./proj5

run1:
	./proj5 proj5_books.txt

val1:
	valgrind ./proj5 proj5_books.txt

clean: 
	rm *~
	rm *.o

test1:
	make Tqueue_test
	./Tqueue_test
