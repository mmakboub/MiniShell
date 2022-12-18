#include<boolean.h>
int check_echo_n(char *arg)
{
    int i = 0;
    while(arg && arg[i])
    {
        if (arg[i] != 'n')
            return(0);
        else
            i++;
    }
    return(1);
    
}

void print_echoarg(char **arg)
{
    int i = 1;
    int j;
    bool check = false;
    bool ok = false;
    while(arg[i])
    {
        j = 0;
        while(arg[i][j])
        {
            if(arg[i][0] && arg[i][0] == '-' && check_echo_n(arg[i]))
                check = true;
            else
            {
                ok = true;
                break;
            }
            j++;
        }
        if (ok)
            break;
        i++;
    }
    while(arg[i])
        printf("%s", arg[i++]);
    if (!check)
        write(1, '\n', 1);
}

void echo(char **arg)
{
    int i = 1;
    if(arg[1] == NULL)
        write(1, "\n", 1);
    else if(arg[1] != NULL)
        print_echoarg(arg);
}