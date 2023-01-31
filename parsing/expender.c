/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:22:07 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/09 01:57:28 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checkvarexist(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (!x && s[i] == '"')
			x++;
		if (s[i] == '\'' && !(x % 2))
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		if (s[i] == 0)
			break ;
		if (s[i] == '$' && \
		(ft_isalnum(s[i + 1]) || s[i + 1] == '_' \
		|| s[i + 1] == '?' || s[i + 1] == '$' || (s[i + 1] == '\'' && !(x % 2)) \
		|| s[i + 1] == '"'))
			return (i);
		i++;
	}
	return (-1);
}

char	**fixed_char(char **str)
{
	int		size;
	char	**newstr;
	int		i;
	int		y;

	size = getsize(str);
	i = 0;
	while (str[i])
		if (str[i++][0] == '\0')
			size--;
	i = 0;
	y = 0;
	newstr = ft_malloc(sizeof(char *) * (size + 1), 1);
	while (str[i])
	{
		if (str[i][0])
			newstr[y++] = ft_strdup(str[i], 1);
		i++;
	}
	newstr[y] = NULL;
	return (newstr);
}

int	takesize(char *s)
{
	int	i;
	int	c;

	i = 0;
	if (*(s + 1) == '?' || *(s + 1) == '$')
		return (2);
	if (*(s + 1) == '"' || *(s + 1) == '\'')
	{
		c = *(s + 1);
		while (s[i] != c)
			i++;
	}
	else
	{
		i = 1;
		while (s[i])
		{
			if (!ft_isalnum(s[i]) && s[i] != '_')
				break ;
			i++;
		}
	}
	return (i);
}

void	rest_expender(t_element *t, int i, char **env)
{
	int		index;
	int		y;
	char	*temp;
	char	*str;

	index = checkvarexist(t->args[i]);
	while (index >= 0)
	{
		y = takesize(&t->args[i][index]);
		if (t->args[i][index + 1] != '\'' && t->args[i][index + 1] != '\"')
		{
			temp = ft_substr(t->args[i], index, y, 1);
			str = takevarvalue(temp, env);
		}
		else
		{
			temp = ft_substr(t->args[i], index + 1, y - 1, 1);
			str = temp;
		}
		t->args[i] = insert(t->args[i], index, str, y);
		index = checkvarexist(t->args[i]);
	}
}

void	expender(t_element *s, char **env)
{
	t_element	*t;
	int			i;

	t = s;
	if (t->type != CMD && t->type != DQUOT && t->type != SQUOT)
		return ;
	i = 0;
	while (t->args[i])
	{
		rest_expender(t, i, env);
		i++;
	}
	t->args = fixed_char(t->args);
	t->cmd = t->args[0];
	delete_quote(s);
}
