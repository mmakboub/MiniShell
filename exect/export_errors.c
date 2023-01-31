/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:27:08 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/07 21:55:09 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unique_export_error(char *str)
{
	if (str[0] == '-')
	{
		printf("minishell: export: -%c: invalid option \n", str[1]);
		printf("export: usage: export [name[=value]...] or export \n");
		g_global.exit_status = 256;
		return ;
	}
}

int	check_is_valid(char *str)
{
	int	i;

	i = 1;
	str = receive_name(str);
	if (str[ft_strlen(str) - 1] == '+')
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1, 0);
	}
	else if (str[0] != '_' && !ft_isalpha(str[0]))
	{
		printf("minishell: export: `%s': not a valid identifier\n", str);
		return (g_global.exit_status = 1, 0);
	}
	check_empty_export(str);
	unique_export_error(str);
	while (str[i] && str[i] != '=')
	{
		if ((!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_'))
		{
			printf("minishell: export: `%s': not a valid identifier\n", str);
			return (g_global.exit_status = 1, 0);
		}
		i++;
	}
	return (1);
}
