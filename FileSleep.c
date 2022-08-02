
    /*   Sleep timer */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>

void Sleep(int time){sleep(time); }

int main(int argc, char* argv[])
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)  perror("Error");
    else { printf("File Succsessfully opened\n");  }

    Sleep(5);
    if (close(fd) == 0)  printf("file succsessfully closed after 15 seconds\n");

    return 0;
}