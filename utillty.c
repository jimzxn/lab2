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

char error_message[30] = "An error has occurred\n";

void out_re(command *cmd, char *out_string)
{
    if (cmd->output_redirect == 0)
    {
        printf("%s\n", out_string);
        return;
    }
    if (cmd->output_redirect == 1)
    {
        int fd = open(cmd->out_redirect_filename, O_TRUNC | O_CREAT | O_WRONLY, 00777);
        if (fd == -1)
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
        int save_out = dup(stdout);
        if (-1 == dup2(fd, stdout))
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
        printf("%s\n", out_string);
        fflush(stdout);
        close(fd);
        dup2(stdout, save_out);
        close(save_out);
        return;
    }
    if (cmd->output_redirect == 2)
    {
        int fd = open(cmd->out_redirect_filename, O_APPEND | O_CREAT | O_WRONLY, 00777);
        if (fd == -1)
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
        int save_out = dup(stdout);
        if (-1 == dup2(fd, stdout))
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
        printf("%s\n", out_string);
        fflush(stdout);
        close(fd);
        dup2(stdout, save_out);
        close(save_out);
        return;
    }
}
void Cd(command *cmd)
{
    if (cmd->argment_count != 1)
    {
        write(STDERR_FILENO, error_message, strlen(error_message));
        return;
    }

    if (strcmp("cd", cmd->cmd_tok[0]))
    {
        if (!strcmp("\0", cmd->cmd_tok[1]))
        {
            chdir(cmd->cmd_tok[1]);
        }
        else
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
            return;
        }
    }
    else
    {
        write(STDERR_FILENO, error_message, strlen(error_message));
        return;
    }
}
void Dir(command *cmd)
{
    char *out = NULL;
    if (cmd->argment_count == 0)
    {
        if ((out = getcwd(out, 0)) == NULL)
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
            return;
        }
        out_re(cmd, out);
        return;
    }
    if (cmd->argment_count == 1)
    {
        char *dirname[2] = cmd->cmd_tok[1];
        DIR *dir = opendir(dirname);
        struct dirent *s;
        if (dir == NULL)
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
            return;
        }
        out_re(cmd, s->d_name);
    }
}
void Env(command *cmd)
{
    if (cmd->argment_count == 0)
    {
        char *out = getenv("USER");
        out_re(cmd, out);
        return;
    }
    write(STDERR_FILENO, error_message, strlen(error_message));
}
void Clr(command *cmd)
{
    printf("\033[H\033[2J");
}
void Pause()
{
    while (1)
    {
        char t = getchar();
        if (t == '\n')
        {
            return;
        }
    }
}
void Echo(command *cmd)
{
    for (size_t i = 0; i < 10; i++)
    {
        printf("%s ", cmd->cmd_tok[i]);
    }
    printf("\n");
}
void quit(int *quit)
{
    quit = 0;
}