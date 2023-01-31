/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:43:18 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 09:07:29 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1, int type)
{
	char	*p;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s1);
	p = (char *)ft_malloc(sizeof(char) * (l + 1), type);
	while (i < l)
	{
		p[i] = s1[i];
		i++;
	}
	p[l] = '\0';
	return (p);
}
