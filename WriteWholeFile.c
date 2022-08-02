
   /*Write Whole file*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

 int main(void)
 {
    int fd1 = 0,  fd2 = 0, iret= 0;
    char buf[1024];
   
    fd1 = open("Demo.txt", O_RDONLY);
    if(fd1 == -1)  perror("Error");
    else { printf("File1 Succsessfully opened\n");  } 

 	while((iret = read (fd1,buf,sizeof(buf))) != 0)
	{
		write ( open("Dmp.txt", O_RDWR | O_CREAT | O_APPEND, 0666) ,buf , iret);
	}

    if(close(fd1) == 0)   printf("File1 Succsessfully closed\n"); 
  
    return 0;
 }


