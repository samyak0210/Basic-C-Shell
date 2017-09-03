#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<termios.h>
#include<sys/utsname.h>
#include<errno.h>
#include<pwd.h>
#include<dirent.h>
#include<grp.h>
#include<time.h>
#include "shell.h"

int main()
{
	getcwd(HOME,sizeof(HOME));
	last=strlen(HOME);
	clrscr();
	while(1){
		int semi=0,q=0;
		int semiColon[10001];
		printPrompt(last,HOME);
		memset (line,'\n',max);
		fgets(line,max,stdin);
		int numCommands=1;
		if((command[0] = strtok(line," \n\t")) == NULL)
			continue;
		while((command[numCommands] = strtok(NULL, " \n\t")) != NULL){
			if(strcmp(command[numCommands],";")==0){
				semi=numCommands;
				semiColon[q++]=numCommands;
			}
			numCommands++;
		}
		if(semi!=numCommands-1)
			semiColon[q++]=numCommands;
		if(!semi)
			execute(command,numCommands);
		else{
			int l=0,r,i;
			for(i=0;i<q;i++){
				r=semiColon[i];
				execute(&(command[l]),r-l);
				l=r+1;
			}
		}
	}
	return 0;
}
