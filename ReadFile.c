
   /* Read File  */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

 int main(void)
 {
    int fd, iret;
    char buf[50];

    fd = open("Demo.txt", O_RDWR);

    if(fd == -1)  perror("Error");
    else { printf("File Succsessfully opened\n");  }
  
    iret = read(fd, &buf, sizeof(buf));
    printf("%d Bytes gets red",iret);
    
    printf("\nActual data is ->  %s ", buf);

    if(close(fd) == 0)     printf("\nFile Succsessfully closed\n");

  
    return 0;
 }
