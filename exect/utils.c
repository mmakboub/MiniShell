/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:40:03 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/07 06:48:22 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_concatenate(const char *s1, const char *s2, const char *s3)
{
	char	*new_str;
	size_t	j;
	size_t	i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	new_str = (char *)ft_malloc((ft_strlen(s1) + \
			ft_strlen(s2) + ft_strlen(s3) + 1) \
			* sizeof(char), 1);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	i = 0;
	while (s3[i])
		new_str[j++] = s3[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	**convertto_doublep(t_env *env)
{
	int		len;
	int		i;
	char	**dp;

	i = 0;
	len = ft_lstsize_env(env);
	dp = (char **)ft_malloc(sizeof(char *) * (len + 1), 1);
	if (!dp)
		exit(1);
	while (env)
	{
		dp[i] = ft_strjoin(env->name, env->value, 1);
		i++;
		env = env->next;
	}
	dp[i] = NULL;
	return (dp);
}

char	*convertto_char(t_env *env)
{
	char	*p;

	p = ft_strjoin(env->name, env->value, 1);
	if (p == NULL)
		return (NULL);
	return (p);
}

int	check_caract(char *str, char c)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_plus(char *str, char c, char x)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] == x)
			return (1);
		i++;
	}
	return (0);
}
