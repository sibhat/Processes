// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Your code here 
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork falied\n");
        exit(1);
    }else if(rc == 0){
        printf("hello, child here (pid: %d) \n", (int) getpid());
        char *myargs[3];
        // `strdup` duplicates the given input string 
        // myargs[0] = strdup("wc");
        myargs[1] = strdup("/bin/ls");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldnot be seen");

    }else{
        int wc = waitpid(rc, NULL, 0);
        printf("hello, parent here here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
