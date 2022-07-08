.PHONY : all clean

all: liblogger.so
	
liblogger.so: lib_mylib.o
	$(CC) -shared -o $@ $^
	
lib_mylib.o: lib_mylib.c
	$(CC) -c -fPIC -I../lib -o $@ $^
	
clean:
	$(RM) *.o *.a
