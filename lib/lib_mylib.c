#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sqlite3.h>
#include <argp.h>
#include <lib_mylib.h>

static sqlite3* db;
static char prog_name[128];
int rc = 0;
char get_time[50];

void get_current_time(void)
{
  	time_t rawtime;
  	struct tm * timeinfo;

  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
	sprintf(get_time, "%d-%d-%d %d:%d:%d",timeinfo->tm_year + 1900,timeinfo->tm_mon + 1,
	timeinfo->tm_mday,timeinfo->tm_hour,
	timeinfo->tm_min,timeinfo->tm_sec);
}

static int callback(void *data, int argc, char **argv, char **azColName) 
{
	int i;
   	fprintf(stderr, "%s", (const char*)data);
   
   	for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   	}
   
   	printf("\n");
	return 0;
}

void read_from_db()
{
	char *zErrMsg = 0;
    char data[]= "CALLBACK FUNCTION :\n";
  	char *sql = "SELECT * FROM LOG;";
	int rcs;

    if (rc) 
	{
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
    }
    else
	{
		printf("Database is open\n");
	}
        
    rcs = sqlite3_exec(db, sql, callback, (void*)data, NULL);
  
    if (rcs != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	sqlite3_free(zErrMsg);
	}
    else 
	{
        printf("Records read successfully\n");
    }
}

void read_from_db_program(char *user_input)
{
	char *zErrMsg = 0;
    char data[]= "CALLBACK FUNCTION :\n";
  	char sql[60];
	int rcs;

	sprintf(sql, "SELECT * FROM LOG WHERE Program_Name = '%s'", user_input);

    if (rc) 
	{
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
    }
    else
	{
		printf("Database is open\n");
	}
        
    rcs = sqlite3_exec(db, sql, callback, (void*)data, NULL);
  
    if (rcs != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	sqlite3_free(zErrMsg);
	}
    else 
	{
        printf("Records read successfully\n");
    }
}

void open_log()
{
	strcpy(prog_name,"log_file.db");
	rc = sqlite3_open(prog_name, &db);
	if(rc)
   	{
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));  
   	}
   else 
	{
      fprintf(stderr, "Opened database successfully\n");
	}
}

void create_table()
{
	char *zErrMsg = 0;
	char sql[200]="";
	int rcs;

   	if(rc)
   	{
      fprintf(stderr, "Database is not found: %s\n", sqlite3_errmsg(db));  
   	}
   else 
	{
      fprintf(stderr, "Database is open\n");
	}

 
   strcpy(sql, "CREATE TABLE IF NOT EXISTS LOG ( \
	'ID' INTEGER PRIMARY KEY AUTOINCREMENT, \
	'Level' INTEGER, \
	'Error' TEXT, \
	'Program_Name' TEXT, \
	'Time'	TEXT)");


   rcs = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
   
   if( rcs != SQLITE_OK )
   {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
   } 
   	else
   	{
    	fprintf(stdout, "Table created successfully\n");
   	}
}

void write_to_log(int level, char *msg, char *name)
{
	char *zErrMsg = 0;
   	char sql[200] = "";
	int rcs;
	char level_name[30];
	create_table();
   	if(rc)
   	{
      fprintf(stderr, "Database is not open: %s\n", sqlite3_errmsg(db));  
   	}
   else 
	{
      fprintf(stderr, "Database is openjkdfsnjlfgdnjfgd\n");
	  
	}

	get_current_time();
	Convert_level(level, level_name);
   	sprintf(sql, "INSERT INTO LOG (Level,Error,Program_Name,Time) "  \
         "VALUES ('%s', '%s', '%s', '%s'); ",level_name, msg, name, get_time);


   rcs = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
   
   if( rcs != SQLITE_OK )
   {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
   } 
   	else
   	{
    	fprintf(stdout, "Logs saved successfully\n");
   	}
}

void close_log()
{
	sqlite3_close(db);
}

void Convert_level(int input, char *output)
{
	if(input==0)
		strcpy(output, "INFO");
		else if(input == 1)
			strcpy(output, "WARNING");
				else if(input == 2)
					strcpy(output, "ERROR");

}