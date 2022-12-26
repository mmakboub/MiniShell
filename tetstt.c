#include"minishell.h"
int main()
{
    int i;
    i = 0;
    char *path = getcwd(NULL, 0);
    const char *join = ft_strjoin("PWD=", path);
    while(join[i])
    {
        write(1, &join[i], 1);
        i++;
    }
    
}