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

int main()
{
  
    int file_desc = open("tricky.txt", O_WRONLY | O_APPEND);
      
    if(file_desc < 0)
        printf("Error opening the file\n");
    int copy_desc = dup2(file_desc, 1);
    write(copy_desc,"This will be output to the file named dup.txt\n", 46);
          
    write(file_desc,"This will also be output to the file named dup.txt\n", 51);
      
    return 0;
}

// int main()
// {
//     int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
      
//     dup2(file_desc, 1) ; 
//     printf("I will be printed in the file tricky.txt\n");
      
// return 0;
// }