/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:22:43 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:42:10 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	str_tokeniser(char **str, t_element **elmnt, int *len)
{
	char	*line;
	int		s;

	line = *str;
	if (*(line - 1) == 32)
		s = 1;
	else
		s = 0;
	while (!issep(*line, "<>|'\"") && *line)
	{
		(*len)++;
		line++;
	}
	add_back(elmnt, line, CMD, *len);
	last(*elmnt)->space = s;
	*len = 0;
	*str = line;
}

void	squote_tokeniser(char **str, t_element **elmnt, int *len)
{
	char	*line;
	int		c;
	int		s;
	int		type;

	line = *str;
	c = *line;
	if (c == '\'')
		type = SQUOT;
	else
		type = DQUOT;
	if (*(line - 1) == 32)
		s = 1;
	else
		s = 0;
	line++;
	(*len)++;
	while (*line != c && *(line++))
		(*len)++;
	line++;
	(*len)++;
	add_back(elmnt, line, type, *len);
	last(*elmnt)->space = s;
	*len = 0;
	*str = line;
}

char	*init_redir_value(int *len, int *c, char **str)
{
	*c = *str[0];
	*len = 1;
	return (++(*str));
}

void	redir_tokeniser(char **str, t_element **elmnt, int *len)
{
	char	*line;
	int		c;

	line = init_redir_value(len, &c, str);
	if (*line == c)
	{
		*len = 2;
		line++;
	}
	if (c == '<')
	{
		if (*len == 1)
			add_back(elmnt, NULL, INF, *len);
		else if (*len == 2)
			add_back(elmnt, NULL, HERDOC, *len);
	}
	else
	{
		if (*len == 1)
			add_back(elmnt, NULL, SUP, *len);
		else if (*len == 2)
			add_back(elmnt, NULL, ADD, *len);
	}
	*len = 0;
	*str = line;
}
