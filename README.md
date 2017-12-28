# Inter-process-Communication
Communication between a producer and a consumer using a text-files.
DATA.txt and TURN.txt are created
Producer reads from mydata.txt and and puts one char at a time into DATA.txt then changes the TURN.txt value from 0  to 1.
Consumer reads from DATA.txt and prints char to screen, then changes the TURN.txt value from 1 to 0.
