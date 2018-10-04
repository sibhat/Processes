// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    int rc = fork();
    // printf("pID (%d)\n", (int) getpid());
    char inbuf[MSGSIZE];
    int p[2];

    if(pipe(p)< 0){
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0){
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("line 36 child pro here pID (%d)\n", (int) getpid());
        exit(0);
    }else{
        waitpid(rc, NULL, 0);
        close(p[1]);
        for (int i = 0; i < 3; i++){
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            close(p[0]);
        }
    }
    printf("parent pro here pID (%d)\n", (int) getpid());
    return 0;
}
