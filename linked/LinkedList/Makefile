CXXFLAGS = -Wall 
CXX = g++

link: main.o ll.o
	$(CXX) $(CXXFLAGS) -o link main.o ll.o

main: main.cc ll.h
	$(CXX) $(CXXFLAGS) -c main.cc

ll.o: ll.cc ll.h
	$(CXX) $(CXXFLAGS) -c ll.cc

clean: 
	-rm -f *.o link a.out
