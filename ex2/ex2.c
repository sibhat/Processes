// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
// Seems like the child and parent process have access to pointer to fopen, and both process can write on that file as they run. 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here 
    FILE *fp = fopen("text.txt", "w+");
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        fprintf(fp, "the value in child (%d) program is %d\n",(int) getpid(), rc);
        exit(1);
        // printf("the x value in child program is %d\n", x);
    }else{
        // printf("the x value in parent program is %d\n", x); 
        int wc = waitpid(rc, NULL, 0);
        fprintf(fp, "the value in parent (%d) program and child ( %d )\n", (int) getpid(), rc);
    }
    fclose(fp);

    return 0;
}
