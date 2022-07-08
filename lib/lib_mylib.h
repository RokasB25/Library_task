void delay(int number_of_seconds);
void get_current_time();
void read_from_db();
void create_table();
void open_log();
void write_to_log(int level, char *msg, char *name);
void close_log();
void read_from_db_program(char *user_input);
void Convert_level(int input, char *output);



#define INFO 0
#define WARNING 1
#define ERROR 2
