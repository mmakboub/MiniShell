/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:32:00 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/26 20:04:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_command *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->type == PIPE)
		handle_pipe();
	else if (cmd->type == CMD)
			execution_cmd(root);
}

