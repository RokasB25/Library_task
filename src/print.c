#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "../lib/lib_mylib.h"



int main(int argc,char *argv[])
{
    char user_input[20];

    if(argv[1]!= NULL)
    {
         printf("entered flag is: %s\n", argv[1]);
         if(strcmp(argv[1], "-p")==0 || strcmp(argv[1], "--program")==0)
         {
            printf("Enter the program name that you want to see the logs of (example : ./test)\n");
            scanf("%s",user_input);
            open_log();
            read_from_db_program(user_input);
            close_log();
         }
         else
         {
            printf("Flag entered does not exist\n");
         }
    }
    else{
        printf("No flag entered\n");
        open_log();
        read_from_db();
        close_log();
    }
   
    return 0;
}