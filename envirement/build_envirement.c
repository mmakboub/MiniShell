# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
void	refresh_oldpwd(t_env	**env, char *pwd)
{
	t_env *tmp;
	tmp = *env;
	while(tmp && strcmp(tmp->name, "OLDPWD"))
		tmp = tmp->next;
	if(tmp && tmp->value)
	{
		free(tmp->value);
		tmp->value = NULL;
		tmp->value = pwd;
	}
}
t_env	*finder_getter(t_env	*env, char *name)
{
	while(env && strcmp(env->name, name))
		env = env->next;
	if(env && env->value)
		return(env);
	return(NULL);
}
void	refresh_pwd(t_env **env)
{
	t_env	*head;
	head = *env;
	while(head && strcmp(head->name, "PWD"))
		head = head->next;
	if(head && head->value)
	{
		free(head->value);
		tmp->value == NULL;
		head->value = getcwd(NULL, 0);
	}
	else
		ft_lstadd_back(ft_lstnew(head->value), &tmp);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	firstc;
	char	*newstr;

	firstc = 0;
	if (!s)
		return (NULL);
	if (start > strlen(s))
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > strlen(s))
		len = strlen(s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (firstc < len && start < strlen(s))
	{
		newstr[firstc++] = s[start++];
	}
	newstr[firstc] = '\0';
	return (newstr);
}

char receive_name(char *allstr)// allstr == line . start reading from 0 until len(strchr(=))
{
    return(ft_substr(allstr, 0, strlen(allstr) - strlen(strchr(allstr, '='))));
}

char receive_value(char *allstr)
{
     return(ft_substr(allstr, strlen(allstr) - strlen(strchr(allstr, '=')), "\0"));
}

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

t_env   *build_env(char **env)
{
    int i;
    t_env   *tmp;

    tmp = NULL;
    i = 0;
    while(env[i])
    {
        ft_lstadd_back(ft_lstnew(env[i]), &tmp);
        i++;
    }
    return(tmp);
}
