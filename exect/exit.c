/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:23:30 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/22 18:57:05 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void printferror(char *str)
{
    write (1, "minishell: exit: ", 17);
	write (1, str, ft_strlen(str));
	write (1, ": numeric argument required\n", 28);
	exit (255);
}
int isalldigits(const char *s)  
{
    int i = 0;
    while(s[i])
    {
        if(!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return(1);
}
int check_exit_status(char *str)
{
    int	i;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
void ft_exit(t_command *command)
{
	int i;
	i = 1;
	int j;
    int exit_status;
    if((command->args[1] && command->args[2])) // && adding function that check if its only a digit) if not it print only minishell to many arg)
	{
		printf("exit\n");
        printf("minishell: exit: too many arguments\n");
	}
   	else if(command->nbr_args == 1)
    {
        printf("%s\n", "exit");
        exit(1);
    }
	while(command->args[i])
	{
		j = 0;
		while(command->args[i][j])
		{
			if(!ft_isdigit(command->args[i][j]))
				printferror(command->args[1]);
			else
				exit(exit_status);
			j++;
		}
		i++;
	}
}