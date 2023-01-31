/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:01:38 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 09:03:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*receive_name_export(char *allstr)
{
	return (ft_substr(allstr, 0, ft_strlen(allstr) - ft_strlen(ft_strchr(allstr,
					'+')), 0));
}

char	*receive_value_export(char *allstr)
{
	return (ft_substr(allstr, ft_strlen(allstr) - \
	ft_strlen(strchr(allstr, '=')) + 1, ft_strlen(allstr), 0));
}

void	check_empty_export(char *str)
{
	if (ft_strlen(str) == 0)
	{
		printf("minishell: export: `%s': not a valid identifier\n", str);
		g_global.exit_status = 1;
		return ;
	}
}
