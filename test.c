#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>
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