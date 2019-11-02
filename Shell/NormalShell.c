#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

#define MAXCOM 1000 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported 

// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 

int takeInput(char* str) 
{ 
	char* buf; 

	buf = readline("\n>>> "); 
	if (strlen(buf) != 0) { 
		add_history(buf); 
		strcpy(str, buf); 
		return 0; 
	} else { 
		return 1; 
	} 
} 

void printDir() 
{ 
	char cwd[1024]; 
	getcwd(cwd, sizeof(cwd)); 
	printf("\nDir: %s", cwd); 
} 

// Function where the system command is executed 
void execArgs(char** parsed) 
{ 
	// Forking a child 
	char* cmd = parsed[0];
	char last = cmd[strlen(cmd) - 1];
	pid_t pid = fork(); 
	if (pid == -1) { 
		printf("\nFailed forking child.."); 
		return; 
	}
	else if (pid == 0) {
		if (last == '&'){
			memmove(&cmd[strlen(cmd) - 1], &cmd[strlen(cmd)], strlen(cmd) - strlen(cmd) + 1);
			pid_t pid1 = fork();

			if (pid1 == -1) { 
				printf("\nFailed forking child.."); 
				return; 
			}
			else if (pid1 == 0) { 
				if (execvp(parsed[0], parsed) < 0) { 
					printf("\nCould not execute command.."); 
				} 
				exit(0); 
			}
			else{
				wait(NULL);
				return;
			}
		} 
		if (execvp(parsed[0], parsed) < 0) { 
			printf("\nCould not execute command.."); 
		} 
		exit(0); 
	} else { 
		// waiting for child to terminate
		wait(NULL); 
		return; 
	} 
} 


// function for parsing command words 
void parseSpace(char* str, char** parsed) 
{ 
	int i; 
	for (i = 0; i < MAXLIST; i++) { 
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL) 
			break; 
		if (strlen(parsed[i]) == 0) 
			i--;
	}
} 
 
int main() 
{ 
	char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
	clear(); 
	while (true) { 
		// print shell line 
		printDir(); 
		// take input 
		if (takeInput(inputString)) 
			continue; 
		// process 
		parseSpace(inputString, parsedArgs); 
		 
		execArgs(parsedArgs);  
	} 
	return 0; 
} 
