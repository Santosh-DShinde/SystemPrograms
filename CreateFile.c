
    /* Create file  */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd ;

    fd = creat ("Demo.txt", 0644);
    if (fd == -1){ perror("Error"); }
    else { printf("File Succsessfully created with File Discriptor %d ", fd); }    
    close(fd);

    return 0 ;
}