
   /* Write File*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

 int main(void)
 {
    int fd;
    const char* buf = "My name is santosh shinde." ;
    ssize_t nt ;
   
    fd = open("Demo.t", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if(fd == -1)  perror("Error");
    else { printf("File Succsessfully opened\n");  }
  
    nt = write(fd, buf, strlen(buf));
    if(nt == -1)  perror("Error");
    else { printf("File Succsessfully written");  }

    close(fd);
  
    return 0;
 }
