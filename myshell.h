struct command_struct
{
    char cmd_tok[10][100];
    int internalcmd;
    int argment_count;
    int input_redirect;//1 for <
    char in_redirect_filenme[100];
    int output_redirect;//1 for > 2 for >>
    char out_redirect_filename[100];
    int pipe;//1 for yes
    char pipe_redirect_filename[100];
    int background;// 1 for yes
};

typedef struct command_struct command;
//utillty
void Cd(command *cmd);
void Dir(command* cmd);
void Env(command *cmd);
void Clr(command *cmd);
void Pause();
void Echo(command *cmd);
void quit(int *quit);
