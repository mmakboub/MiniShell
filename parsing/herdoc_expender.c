/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_expender.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:38:53 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:40:54 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	takesize_her(char *str)
{
	int	i;

	i = 0;
	str++;
	if (str[i] == '?')
		return (2);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i + 1);
}

int	get_var_index(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] == '$' && (ft_isalnum(line[i + 1]) || line[i + 1] == '_'
				|| line[i + 1] == '?'))
			return (i);
	return (-1);
}

char	*mygetline(char *line, int index, char **env)
{
	char	*str;
	char	*temp;
	char	*temp_sub;
	int		i;

	i = 0;
	while (index > -1)
	{
		i = takesize_her(&line[index]);
		temp_sub = ft_substr(line, index, i, 1);
		str = takevarvalue(temp_sub, env);
		temp = line;
		line = insert(line, index, str, i);
		index = get_var_index(line);
	}
	return (line);
}

void	herdoc(t_element *s, char **env)
{
	char	*line;
	int		index;

	g_global.sig = 1;
	if (pipe(s->pip) == -1)
		exit(1);
	line = readline("> ");
	add_back_memory(line, 1);
	while (line && ft_strcmp(line, s->next->args[0]) \
	&& g_global.exit_heredoc == 1)
	{
		index = get_var_index(line);
		if (index > -1)
			line = mygetline(line, index, env);
		write(s->pip[1], line, ft_strlen(line));
		write(s->pip[1], "\n", 1);
		line = readline("> ");
		add_back_memory(line, 1);
	}
	g_global.exit_heredoc = 0;
	close(s->pip[1]);
}
