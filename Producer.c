#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void producer(){

	FILE *mydata; //declare file pointer
	FILE *DATA;
	FILE *TURN;
	mydata = fopen("mydata.txt", "r");
	if (mydata==NULL) {printf("No mydata file\n"); exit(1);} //checks if mydata.txt exists

	while(!feof(mydata)){
		
		
		char turn = '1';

		//check if it is our turn (turn = 0) else keep verifying the value of 'turn'
		while(turn == '1')
		{
			while( (TURN = fopen("TURN.txt", "r")) == NULL);
			
			turn = fgetc(TURN);
				
			fclose(TURN);	
			
			
		}
			if(turn == '0')
			{			
				char c = getc(mydata);
				
				//writing char to DATA-file
				DATA = fopen("DATA.txt", "w+");
				if (DATA == NULL) {printf("Unable to open DATA\n"); exit(1);}
				fputc(c, DATA);
				fclose(DATA);

				//overwrite turn-file
				while( (TURN = fopen("TURN.txt", "r+")) == NULL);
				fputc('1', TURN);
				fclose(TURN);	
				

			}
			

		
	}
	fclose(mydata);
	

}
