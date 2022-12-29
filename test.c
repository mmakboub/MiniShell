#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>
#include"./exect/minishell.h"
#include <fcntl.h>
// int main(int ac, char **av, char **env)
// {
//     char *pwd;
//     t_env *p;
//     p = build_env(env);
//     pwd =getcwd(NULL, 0);
//     char *t = printf("PWD=%s",pwd);
//     printf("\n");
//     ft_lstadd_back(ft_lstnew(t),&p);
// }
// int main()
// {
//     int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
      
//     dup2(file_desc, 1) ; 
//     printf("I will be printed in the file tricky.txt\n");
      
// return 0;
// }
// int main(int ac , char **av)
// {
    
//     if ((ac == 1) || ((ac == 2) && ((av[1][0] == '#') || (av[1][0] == '~'))))
//         printf("hi meryem\n");
//     else if (ac > 1)
//         printf("meriem fenna\n");
//     return(0);
// }
// int	ft_isdigit(int x)

// {
// 	if (x >= '0' && x <= '9')
// 		return (1);
// 	return (0);
// }
// int isalldigits(const char *s)  
// {
//     int i = 0;
//     while(s[i])
//     {
//         if(!ft_isdigit(s[i]))
//             return (0);
//         i++;
//     }
//     return(1);
// }

// int main()
// {
//     const char p[10] = "dfghh";
//     if (isalldigits(p))
//         printf("ok\n");
//     else
//         printf("ko\n");
//     return(0);
// }

int	ft_lstsize(t_env *lst)

{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

char **convertto_doublep(t_env *env)
{
	int len;
	int i;
	char **dp;
	i = 0;
	len = ft_lstsize(env);
	dp = (char **)malloc(sizeof(char *) * (len +1));
	while (env)
	{
		dp[i] = ft_strjoin(env->name, env->value);
		i++;
		env = env->next;
	}
	dp[i] = NULL;
	return(dp);
}
int main()
{
    t_env *env;
    env = malloc(sizeof)

}