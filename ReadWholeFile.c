
    /* Read Whole File  */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

 int main(void)
 {
    int fd, iret;
    char buf[10];

    fd = open("Demo.txt", O_RDWR);

    if(fd == -1)  perror("Error");
    else { printf("File Succsessfully opened\n");  }
  
    while (iret = read(fd, &buf, sizeof(buf)) != 0)
    {
        printf("%s", buf);
    }
    printf("%d Bytes gets red",iret);

    if(close(fd) == 0)     printf("File Succsessfully closed\n");
  
    return 0;
 }
