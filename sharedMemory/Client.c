#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ 27
main()
{
    char c;
    int shmid;
    key_t key = 5768;

    char *shm, *s;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    printf("success\n");
    for (s = shm; *s != NULL; s++)
    {
        putchar(*s);
    }
    putchar('\n');
    shm[1] = '*';
    exit(0);
}
