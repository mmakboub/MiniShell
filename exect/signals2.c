/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:18:08 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 10:33:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	handling_sig(void)
{
	rl_catch_signals = 0;
	if (signal(SIGINT, handler) == SIG_ERR || signal(SIGQUIT,
			SIG_IGN) == SIG_ERR)
	{
		write(2, "sig error\n", 10);
		exit(1);
	}
}

void	lineisempty(char *line)
{
	char	*sr_cap;

	g_global.exit_heredoc = 1;
	rl_event_hook = event;
	add_back_memory(line, 1);
	if (!line)
	{
		sr_cap = tgetstr("sr", NULL);
		tputs(sr_cap, 0, ft_putchar);
		printf("minishell> exit\n");
		free_memory(0);
		exit(g_global.exit_status);
	}
}
