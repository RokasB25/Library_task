#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sqlite3.h>
#include <argp.h>
#include <lib_mylib.h>


int main(int argc, char *argv[])
{
	char program_name[15];
	strcpy(program_name,argv[0]);

	printf("program's name is: %s\n",program_name);
	open_log();
	write_to_log(ERROR, "Program didint work successfully", program_name);
	close_log();

	return 0;
}