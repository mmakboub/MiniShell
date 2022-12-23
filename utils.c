/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:40:03 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/23 16:40:26 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_env	*ft_lstnew(char *allstr)
{
	t_env	*newelement;

	newelement = (t_env *)malloc(sizeof(t_env));
	if (newelement == 0)
		return (0);
    newelement->name = receive_name(allstr);
	newelement -> value = receive_value(allstr);
	newelement -> next = NULL;
	return (newelement);
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
int countArg(char **str) 
{
    int i;

    i = 0;
    while (*str[i])
        i++;
    return (--i);
}

