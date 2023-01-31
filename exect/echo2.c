/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/20 19:01:01 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 00:46:49 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_echo_n(char *arg)
{
	int	i;

	i = 1;
	while (arg && arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		else
			i++;
	}
	return (1);
}

static void	print_arg(char **arg, int i, bool check)
{
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1])
			printf(" ");
		i++;
	}
	if (!check)
		printf("\n");
}

void	print_echoarg(char **arg)
{
	int		i;
	bool	check;

	check = false;
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] && arg[i][0] == '-' && check_echo_n(arg[i]))
			check = true;
		else
			break ;
		i++;
	}
	print_arg(arg, i, check);
}

void	echo2(char **arg)
{
	if (arg[1] == NULL)
		write(1, "\n", 1);
	else if (arg[1] != NULL)
		print_echoarg(arg);
	g_global.exit_status = 0;
}
