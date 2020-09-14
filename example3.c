#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int i, status;
    pid_t pid, pid_array[3];

    printf("My process ID is %d\n", getpid());
    for (i = 0; i < 3; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("I am the child => PID = %d\n", getpid());
            while (1)
                ;
        }
        else
        {
            printf("I am the parent => PID = %d, child ID = %d\n", getpid(), pid);
            pid_array[i] = pid;
        }
    }

    for (i = 0; i < 3; i++)
    {
        printf("Status before wait is %d\n", status);
        if (pid = wait(&status))
        {
            printf("Status after wait %d\n", status);
            printf("Process ID %d has terminated\n", pid);
        }
    }
}
