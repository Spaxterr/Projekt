project: main.o contactmanager.o filemanager.o
	g++ -Wall main.o contactmanager.o filemanager.o -o output

main.o: main.cpp
	g++ -c main.cpp

contactmanager.o: contactmanager.cpp contactmanager.h
	g++ -c contactmanager.cpp

filemanager.o: filemanager.cpp filemanager.h contactmanager.o
	g++ -c filemanager.cpp

clean:
	rm *.o output
