#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"


int main(){
	FILE *TURN = fopen("TURN.txt", "w");
	fputc('0', TURN);
	fclose(TURN);	
	
	
	int pid = fork();
	
	if(pid == -1) {exit(1);}
    if(pid != 0) {producer(); wait(NULL);}
    if(pid == 0) {consumer();}

	
	

}