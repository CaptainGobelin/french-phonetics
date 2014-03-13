CC=g++
CFLAGS=-Wall
LDFLAGS=
EXEC=phonetics
OBJ=main.o

%.o : %.cpp %.h
	$(CC) -c $*.cpp $(CFLAGS)

main.o :
	$(CC) -c main.cpp $(CFLAGS)  

phonetics : $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 
	rm -rf *.o

clean:
	rm -rf *.o
