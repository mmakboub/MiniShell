/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:22:18 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/06 15:35:23 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_rest_error(int type, int next)
{
	if (next == ADD && type != PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 1);
		return (1);
	}
	if (next == SUP && type != PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 1);
		return (1);
	}
	if (next == INF && type != PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 1);
		return (1);
	}
	return (0);
}
