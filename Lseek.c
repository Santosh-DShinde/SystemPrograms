
    /* lseek Function */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0, f1 ;
    fd = open("Demo.txt", O_RDWR);
    if(fd == -1)  perror("Error");
    else  printf("File Demo.txt Succsessfully opened\n");

    f1 = lseek(fd, 10, SEEK_CUR);

    printf("Pointer  position is %d ", f1);

    if(close(fd) == 0)     printf("\nFile Succsessfully closed\n");

    return 0;
}
