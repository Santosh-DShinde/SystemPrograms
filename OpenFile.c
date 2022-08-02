
    /* Open File  */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd ;

    fd = open("Demo.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd == -1)  perror("Error");
    else { printf("File Succsessfully opened");  }

    if(close(fd) == 0)     printf("\nFile Succsessfully closed\n");

    return 0;
}
