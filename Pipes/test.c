#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char info[50];

main()
{
    int fdr;
    int rc = mknod("testfile", 'b', 0);
    if (rc < 0)
    {
        perror("Error in mnod");
    }
    fdr = open("testfile", O_RDONLY);
    read(fdr, info, 50);
    printf("\n Received message=%s", info);
    printf("\n");
}