Raja R C Kantheti

I have neither given nor received unauthorized assistance on this work.

#################################################################################################################################

Machine Location: rkanthet/rkanthetCentOS
username: rkanthet
password: 12345678 (same for root)
Path of the code: /home/rkanthet/project1

#################################################################################################################################

Instructions to run the program:

1.Navigate to above source directory in terminal
2. Execute the command "make".

#################################################################################################################################

Expected output:

gcc -Wall -Wextra -std=c99 list.c list_test.c -o list_test
./list_test
The linked list has been created.

Node 1
Node 2
Node 3
Node 4
Node 5


Node 4
Node 5

List is empty or Non-Existent

Node 1
Node 2
Node 3
Node 4
Node 5

Link list has been freed from memory, no more operations permitted after this point% 

#################################################################################################################################

Challenges I had to overcome while doing this assignment: 

1. Challenges I had to overcome while doing this assignment:
Warnings regarding the return of  strdup(), had to learn CENTOS requires macro
 _POSIX_C_SOURCE to be declaered before including <string.h> header file. Did that and the program compiled without any warnings.

2. Makefile basics, learned it from youtube, since this assignment doesn't demand a complete understanding of the feature. 

#################################################################################################################################

The assignment has three files, a header file, list.h, with function prototypes, list.c with the implementations of the functions from
the header file, and list_test.c file with the mechanism to invoke those functions. 
