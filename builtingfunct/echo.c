/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:00:24 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/24 17:06:25 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
int check_n(char **arg)
{
    if(arg[i] && arg[i][0] == '-' && arg[i][1] == 'n')
        {
            int j = 0;
            while(arg[i][j] && arg[i][j] == 'n')
                j++;
            if(arg[i][j] == '\0')
            {
                i++;
                return(1)
            }
            
    
}
void check_echo(char **arg)
{
    int i = 1;
    while(arg[i])
    {
        check_n(arg)
        
    }
}
void echo(char **arg)
{
    int i = 1;
    if(arg[1] == NULL)
        write(1, "\n", 1);
    else if(arg[1] != NULL)
        check_echo(arg);
}
int main(int ac, char **av)
{
    char *prompt = "minishell > ";
    char *input = readline(prompt);
    if(!input) // for EOF error
      exit(0);
    add_history(input);
    echo(av);
    free(input);
}