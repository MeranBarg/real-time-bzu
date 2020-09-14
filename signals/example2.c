// #include <stdlib.h>
#include <stdio.h>
#include <signal.h>
// #include <bits/types.h>

sigset_t mask_set;
sigset_t old_set;
__sighandler_t old_handler;
void catch_int(int);

int main()
{

    old_handler = signal(SIGINT, catch_int);
    /* change the handler of SIGINT to perform the function ctrl_c
    // and return the location of the old default function */
    // while ((c = getchar()) != '\n')
    //     ;
    // printf("ctrl_c count = %d\n", ctrl_c_count);
    // (void)signal(SIGINT, old_handler);

    while (1)
        ;
}

void catch_int(int sig_num)
{
    long int i = 0;
    // signal(SIGINT, catch_int);
    // sigfillset(&mask_set);
    sigaddset(&mask_set, SIGINT);
    sigprocmask(SIG_SETMASK, &mask_set, &old_set);

    for (i = 0; i < 100000; i++)
    {
        printf("%ld\n", i);
    }

    sigprocmask(SIG_SETMASK, &old_set, &mask_set);
    (void)signal(SIGINT, old_handler);
}
