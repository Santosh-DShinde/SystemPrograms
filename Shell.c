#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int DirectoryTravel(char *path, int iNo)
{
    DIR *dir;
    int fd, i = 0;
    struct stat filestat;
    struct dirent *dp;

    dir = opendir(path); 
    if (dir == NULL)
    {
        printf("Error   : unable to open directory %s\n", path);
        printf("\t| check provided path is correct or not");
    }
    else
    {
        if(iNo == 0)    printf("\t| File Names\n\n");
        if (iNo == 2)   printf("\t| File Names\t\t| inode numbers\n\n");
        while((dp = readdir(dir)) != NULL)
        {
            fd = open(dp->d_name, 0444);
            if (iNo == 2)
            {
                if (fstat(fd, &filestat) != -1)
                    printf("\t|  %s\t\t\t%ld  \n", dp->d_name, filestat.st_ino);
            }
            else if(iNo == 0) 
                printf("\t %s\n",dp->d_name);
            i++;
            close(fd);
        }
        if(iNo == 1)    return i;
    }
}

void DisplayHelp()
{
	printf(" clear          : TO CLear Console \n");
	printf(" exit           : TO Terminate Terminal Myshell$\n");
	printf(" help           : TO Get help\n");
	printf(" f path         : TO Print name of all files in directory\n");
	printf(" list n path    : TO Get the number of all entries\n");
	printf(" list i path    : TO Get the name of all file and inodes of files\n");
}

int main(int argc, char const *argv[])
{
    char command[4][80], str[80];
    int count = 0, i = 0;

    while (1)
    {   
        fflush(stdin);
        strcpy(str, "");
        printf("\nLinux@Ubuntu$ ");
        fgets(str,80,stdin);

        count = sscanf(str, "%s %s %s %s", command[0], command[1], command[2], command[3]);

     if (count == 1)
        {
           	if (strcmp(command[0],"exit")==0)
	        {
		        printf("Terminating The MyShell\n");
		        break;
	        }
            else if (strcmp(command[0],"clear")==0)
	        {
		        system("clear");
		        continue;
	        }
        	else if (strcmp(command[0],"help")==0)
	        {   
		        DisplayHelp();
		        continue;
	        }
            else
	        {
		        printf("\nError : Command '%s' not Found !!!\n",command[0]);
		        continue;
	        }
        }

     else if (count == 2)
        {
            if(strcmp(command[0], "f") == 0)
            {
                i = DirectoryTravel(command[1], 0);
            }
            else
            {
		        printf("\nError : Command '%s' not Found  !!!\n",command[0]);
		        continue;
	        }
        }

     else if (count == 3)
        {
            if(strcmp(command[0], "list") == 0);
            {
                if(strcmp(command[1], "n") == 0)
                {
                    printf("Number of all entries : %d\n",DirectoryTravel(command[2], 1));
                }
                else if(strcmp(command[1], "i") == 0)
                {
                    DirectoryTravel(command[2], 2);
                }
        else{       printf("\nError : Command '%s' not Found !!!\n",command[1]);    continue;  }
            }
        }
        else{  printf("\nError : Command not Found !!!\n");  continue;  }
    }
   return EXIT_SUCCESS;
}





