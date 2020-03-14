struct command_struct
{
    char cmd_tok[10][100];
    int internalcmd;
    int input_redirect;
    char in_redirect_filenme[100];
    int output_redirect;
    char out_redirect_filename[100];
    int pipe;
    char pipe_redirect_filename[100];
    int background;
};

typedef struct command_struct command;

