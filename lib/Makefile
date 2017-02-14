CC = g++
CFLAGS = -Wall -std=c++11 -fPIC
LFLAGS = -shared

BOOST_SYS = /usr/lib/x86_64-linux-gnu/libboost_system.so.1.58.0

# program: 
#	$(CC) 


main: libsession.so
	${CC} ${CFLAGS} -I -L. ../test/test_main.cpp -o main libsession.so  ${BOOST_SYS}

libsession.so: session.o file_session.o log_session.o
	${CC} -o $@ session.o file_session.o log_session.o ${BOOST_SYS}  ${LFLAGS} 
	rm -rf *.o


session.o: 
	$(CC) -c ${CFLAGS} ../src/base/Session.cpp
	mv Session.o session.o
	
file_session.o: session.o
	$(CC) -c ${CFLAGS} ../src/file/fileSession.cpp session.o  ${BOOST_SYS} 
	mv fileSession.o file_session.o
	
log_session.o: file_session.o
	$(CC) -c ${CFLAGS} ../src/log/logSession.cpp file_session.o
	mv logSession.o log_session.o
	
clean:
	rm -rf *.o *.so *.a 
