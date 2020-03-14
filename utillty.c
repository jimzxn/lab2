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

char error_message[30] = "An error has occurred\n";

void cd(command* cmd){
    if (strcmp("cd",cmd->cmd_tok[0]))
    {
        chdir(cmd->cmd_tok[1]);
    }else
    {
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
}