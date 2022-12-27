/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:40:03 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/26 19:44:18 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"
t_env	*ft_lstnew(char *allstr, int flag)
{
	t_env	*newelement;

	newelement = (t_env *)malloc(sizeof(t_env));
	if (newelement == 0)
		return (0);
    newelement->name = receive_name(allstr);
	if(flag == 1)
		newelement -> value = receive_value(allstr);
	else
		newelement -> value = receive_value_export(allstr);	
	newelement -> next = NULL;
	return (newelement);
}
char *receive_value_export(char *allstr)
{
     return(ft_substr(allstr, strlen(allstr) - strlen(strchr(allstr, '=')), strlen(allstr)));
}
void	ft_lstadd_back(t_env *new, t_env **alst)
{
	t_env	*node;

	node = *alst;
	if (alst && *alst)
	{
		while (node-> next)
		{
			node = node->next;
		}
		node->next = new;
	}
	else
		*alst = new;
}
char	*concatenate(const char *s1, const char *s2, const char *s3)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s3;
	size_t	j;
	size_t	i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	len_s3 = strlen(s3);
	new_str = (char *)malloc((len_s1 + len_s2 + len_s3 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	i = 0;
	while(s3[i])
		new_str[j++] = s3[i++];
	new_str[j] = '\0';
	return (new_str);
}

int countArg(char **str) 
{
    int i;

    i = 0;
    while (*str[i])
        i++;
    return (--i);
}