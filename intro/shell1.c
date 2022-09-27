#include <sys/wait.h>

#include "apue.h"

int main(int argc, const char *argv[])
{
    char buf[MAXLINE] = {0}; /* from apue.h */
    pid_t pid = 0;
    int status = 0;

    printf("%% "); /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        { /* child */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }
        
        printf("%% ");
    }
    
    exit(0);
}
