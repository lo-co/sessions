CC = g++
CFLAGS = -Wall -std=c++11 -fPIC
LFLAGS = -shared

# program: 
#	$(CC) 


session.so: session.o
	${CC} -o $@ session.o ${LFLAGS}


session.o: 
	$(CC) -c ${CFLAGS} ../src/base/Session.cpp

clean:
	rm -rf *.o *.so *.a 
