/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:21:57 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/09 00:17:22 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*insert(char *str, int index, char *s, int sz)
{
	int		size;
	int		i;
	int		y;
	char	*temp;

	size = ft_strlen(str) - sz + ft_strlen(s);
	temp = str;
	str = ft_malloc(sizeof(char) * (size + 1), 1);
	i = -1;
	while (++i < index)
		str[i] = temp[i];
	while (*s)
		str[i++] = *(s++);
	y = index + sz;
	while (temp[y])
		str[i++] = temp[y++];
	str[i] = 0;
	return (str);
}

char	*takevarvalue(char *str, char **env)
{
	int		i;
	char	*s;
	char	*ret;
	int		sz;

	s = ft_strjoin(str + 1, "=", 1);
	i = 0;
	sz = ft_strlen(s);
	ret = NULL;
	if (!ft_strcmp(str, "$?"))
		return (ft_itoa(g_global.exit_status, 1));
	if (!ft_strcmp(str, "$$"))
		return (ft_itoa(getpid(), 1));
	while (env[i])
	{
		if (!ft_strncmp(s, env[i], sz))
			ret = ft_strdup(&env[i][sz], 1);
		i++;
	}
	if (ret == NULL)
		ret = ft_strdup("", 1);
	return (ret);
}
