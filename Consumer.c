#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void consumer()
{
        
        FILE* DATA; //declare file pointer
        FILE* TURN;
        char data;
        char turn = '0'; 
              
    while(1)
    { 
        //do not continue with process until it is our turn (turn = 1)
        while(turn == '0')
        {
            while( (TURN = fopen("TURN.txt", "r")) == NULL);
            turn = fgetc(TURN);
            
            fclose(TURN);
           
            
        }

        if (turn == '1') 
        {
           
            //print char from DATA-file
            while ( (DATA = fopen("DATA.txt", "r")) == NULL);
            data = fgetc(DATA);
            fclose(DATA);
            if (data == EOF) {
                break;
            }
            printf("%c", data);

            //overwrite TURN-file
            while( (TURN = fopen("TURN.txt", "r+")) == NULL);
            fputc('0',TURN);
            fclose(TURN);
            turn = '0'; //switch to producer

        }
       

    }
}
