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
	write(1, "exit\n", 5);
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
long check_exit_status(char *str)
{
    int	i;
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
// void ft_exit(t_command *command)
// {
// 	int i;
// 	i = 1;
 
//     if((command->args[1] && command->args[2])) // && adding function that check if its only a digit) if not it print only minishell to many arg)
// 	{
// 		printf("exit\n");
//         printf("minishell: exit: too many arguments\n");
// 	}
//    	else if(command->nbr_args == 1)
//     {
//         printf("%s\n", "exit");
//         exit(1);
//     }
// 	else if (command->nbr_args == 2)
// 		check_arg(command);
// }

// void	check_arg(t_command *command)
// {
// 	int i = 1;
// 	long exit_status;
// 	if(((isalldigits(command->args[i]) && ft_strlen(command->args[i]) > 19) || !isalldigits(command->args[i])))
// 		printferror(command->args[i]);
// 	else if(isalldigits(command->args[i]))
// 	{
// 		exit_status = check_exit_status(command->args[i]);
// 		printf("%ld", exit_status);
// 		if(exit_status < 0)
// 		{
// 			printf("exit\n");
//             exit(256 - ((exit_status * -1) % 256));
// 		}
// 		else
// 		{
// 			printf("exit1\n");
// 			exit(exit_status % 256);
// 		}
// 	}
// 	i++;
// }

void ft_exit(t_command *command)
{
    long exit_status;
    if(command->nbr_args == 1)
    {
        printf("%s\n", "exit");
        exit(0);
    }
	else if(!isalldigits(command->args[1]) || ft_strlen(command->args[1]) > 20)
		printferror(command->args[1]);
    else if((command->args[1] && command->args[2])) // && adding function that check if its only a digit) if not it print only minishell to many arg)
	{
		printf("exit\n");
        printf("minishell: exit: too many arguments\n");
	}
	else
	{
		exit_status = check_exit_status(command->args[1]);
		if(exit_status < 0)
				exit(256 - ((exit_status * -1) % 256));
		exit(exit_status % 256);
	}
	
}