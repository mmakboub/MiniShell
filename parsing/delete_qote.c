/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_qote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:21:43 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/09 01:10:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*deleteone(char *s, int index, int x)
{
	int		i;
	int		y;
	char	*str;

	str = ft_malloc(sizeof(char) * ft_strlen(s) - 1, 1);
	if (!str)
		exit(1);
	i = 0;
	y = 0;
	while (s[i])
	{
		while (i == index || i == x)
			i++;
		if (!s[i])
			break ;
		str[y++] = s[i++];
	}
	str[y] = 0;
	return (str);
}

int	rest_delete(t_element *t, int i, int *y)
{
	char	*temp;
	int		c;
	int		p;

	c = 0;
	if (t->args[i][*y] == '\'')
		c = '\'';
	if (t->args[i][*y] == '"')
		c = '"';
	if (c)
	{
		p = (*y)++;
		while (t->args[i][*y] && t->args[i][*y] != c)
			(*y)++;
		if (!t->args[i][*y])
			return (1);
		temp = t->args[i];
		t->args[i] = deleteone(t->args[i], p, *y);
		*y -= 1;
		if (t->args[i][*y] == 0)
			return (1);
	}
	return (0);
}

void	delete_quote(t_element *t)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (t->args[i])
	{
		y = 0;
		while (t->args[i][y])
		{
			if (t->args[i][y] == '\'' || t->args[i][y] == '"')
			{
				if (rest_delete(t, i, &y))
					break ;
			}
			else
				y++;
		}
		i++;
	}
	t->cmd = t->args[0];
}
