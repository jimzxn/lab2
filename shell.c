#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include "myshell.h"
#include <dirent.h>

void tokenize(char*input,char**output){
    
}
int main(int argc, char *argv[])
{
    char *line = NULL; //need free
    size_t len = 100;
    ssize_t read;
    if (argc == 2)
    {
        int fd = open(argv[1], O_TRUNC | O_CREAT | O_WRONLY, 00777);
        if (fd == -1)
        {
            exit(-1);
        }
        int save_input = dup(stdin); //need to be close and recover when quit excute
        if (-1 == dup2(fd, stdin))
        {
            exit(-1);
        }
    }

    while ((read = getline(&line, &len, stdin)) != -1)
    {

        int c=0;
        
        
        
    }
}