#include <stdio.h>
#include <signal.h>
//#include <unistd.h>

int ctrl_c_count = 0;
__sighandler_t old_handler;
__sighandler_t new_handler;
void ctrl_c(int);

void main()
{
    int c; // stores character from stdin
    new_handler = &ctrl_c;
    old_handler = signal(SIGINT, new_handler);
    /* change the handler of SIGINT to perform the function ctrl_c
    and return the location of the old default function */
    while ((c = getchar()) != '\n')
        ;
    printf("ctrl_c count = %d\n", ctrl_c_count);
    (void)signal(SIGINT, old_handler);

    while (1)
        ;
}

void ctrl_c(int signum)
{
    // (void)signal(SIGINT, ctrl_c);
    ++ctrl_c_count;
}