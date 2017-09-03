#ifndef SHELL_H
#define SHELL_H

#define GREEN   "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"
#define max 1000001
#define limit 1000001
#define e_l printf("\n");
#define err printf("Error\n");
#define clrscr() printf("\e[1;1H\e[2J");

char *command[limit];
char line[max];
int last;
char s[100001];
char HOME[1024];
int bgp;

void printPrompt();

void pinfo(char ** command);

void changeDir(char ** command);

void list(char ** command,int numCommands);

void Exec(char ** command,int numCommands);

void execute(char ** command,int numCommands);

void pwd();

void echo(char ** command,int numCommands);

#endif
