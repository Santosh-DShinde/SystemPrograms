

    /* File size and file type */

#include<stdio.h>
#include<fcntl.h> 
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>


int main(int argc, char* argv[])
{
    struct stat fileInfo;
    int fd = 0, Rt = 0;

    printf("Number of cmd line args accepted is : %d\n",argc-1);
    
    fd = open(argv[1], O_RDONLY);

    Rt = fstat(fd, &fileInfo);
    printf("Size of file is : %ld Bytes\n", fileInfo.st_size);

   printf("File Type Of '%s' file is .%s\n",argv[1], strchr(argv[1], '.')+1);

    if(close(fd) == 0)     printf("\nFile Succsessfully closed\n");
    
    return 0;
}