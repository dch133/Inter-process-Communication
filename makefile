A6 : main.o Producer.o Consumer.o
	gcc -o A6 main.o Producer.o Consumer.o

main.o: main.c 
	gcc -c main.c

Producer.o: Producer.c 
	gcc -c Producer.c

Consumer.o: Consumer.c
	gcc -c Consumer.c
