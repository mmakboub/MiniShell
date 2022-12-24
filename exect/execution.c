/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:32:00 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/25 00:33:19 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_command *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->type == PIPE)
		pipe
	else if (root->type == CMD)
	{
		if (root->rdrlst)
			redirection(root);
		else
			execution_cmd(root);
	}
}

