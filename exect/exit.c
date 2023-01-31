/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/22 14:23:30 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/22 18:57:05 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printferror(char *str)
{
	write(1, "minishell: exit: ", 17);
	write(1, str, ft_strlen(str));
	write(1, ": numeric argument required\n", 28);
	g_global.exit_status = 255;
	exit(255);
}

int	isalldigits(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

long	check_exit_status(char *str)
{
	int		i;
	long	result;
	long	sign;

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

void	ft_exit(t_element *command)
{
	long	exit_status;

	printf("%s\n", "exit");
	if (command->nbr_args == 1)
		exit(0);
	else if (!isalldigits(command->args[1]) \
		|| ft_strlen(command->args[1]) > 20)
		printferror(command->args[1]);
	else if ((command->args[1] && command->args[2]))
	{
		printf("minishell: exit: too many arguments\n");
		g_global.exit_status = 1;
	}
	else
	{
		exit_status = check_exit_status(command->args[1]);
		if (exit_status < 0)
			exit(256 - ((exit_status * -1) % 256));
		exit(exit_status % 256);
	}
	g_global.exit_status = 0;
}
