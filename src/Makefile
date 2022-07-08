.PHONY : all clean

all:
	$(CC) -I../lib -c test.c -o test.o
	$(CC) -I../lib -Wall -o test test.c  -L../lib -llogger -lsqlite3
	$(CC) -I../lib -c print.c -o print.o
	$(CC) -I../lib -Wall -o print print.c  -L../lib -llogger -lsqlite3 
	$(CC) -I../lib -c program.c -o program.o
	$(CC) -I../lib -Wall -o program program.c  -L../lib -llogger -lsqlite3 

clean:
	$(RM) *.o *.so
