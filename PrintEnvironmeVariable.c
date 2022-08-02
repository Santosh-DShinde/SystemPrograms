

/*  Print environment variable  */

#include<stdio.h>

int main(int argc, char* argv[], char* envp[])
{
    int i = 0;

    for(i = 0; envp[i] != NULL ; i++)
    {
        printf("\n%s", envp[i]);
    }

    return 0 ;

}