// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? 
// What happens to the variable when both the child and parent change the value of x?
// Answer: The change for the variable will only be in local scop no matter if parent of child change the value of it. 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    // Your code here
    printf("parent (pid: %d)\n", (int) getpid());
    int x = 31;
    int rc = fork();
 
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        x = 41;
        printf("Line 25 the x value in child (%d) program is %d\n",(int) getpid(), x); // output x = 41
        exit(1);
    }else{
        x = 61;
    }
    // waitpid(rc, NULL, 0); 
    
    printf("Line 32 the x value in parent (%d) program is %d\n",(int) getpid(), x);   // output x  = 61
    
    return 0;
}
