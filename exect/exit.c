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

#include"minishell.h"
void printferror(char *str)
{
    write (1, "minishell: exit: ", 17);
	write (1, str, ft_strlen(str));
	write (1, ": numeric argument required\n", 28);
	exit (255);
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
void exit(t_command *command)
{
	int i;
	i = 1;
	int j;
    int exit_status;
	exit_status = check_exit_status(command->args[1]);
    if(command->args[1] && command->args[2])
	{
		printf("exit\n");
        printf("minishell: exit: too many arguments");
	}
    if(command->nb_args == 1)
    {
        printf("%s\n", "exit");
        exit(0);
    }
	while(command->args[i])
	{
		j = 0;
		while(command->args[i][j])
		{
			if(exit_status == 0 && !ft_isdigit(command->args[i][j]))
				printferror(command->args[1]);
			else
				exit(exit_status);
		}
	}
}