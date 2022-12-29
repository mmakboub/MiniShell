/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:57:46 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 18:22:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char *execute_cmd(t_command *command, t_env **env)
{
	char *line;
	char *path;
	char **splited_path;
	int i;
	if(check_accecs_exec(command->cmd))//todo : ADD another fonction that check only accessibility while the path is executable and replace it in this line (nammed :check_access)
		return (strdup(command->cmd));
	line = convertto_char(finder_getter(*env,"PATH"));
	if(!line)
		return(NULL);
	splited_path = ft_split(line, ':');
	if(!splited_path)
		return(NULL);
	path = join_get_acces(splited_path, command->cmd);
    if (!path)
		return(NULL);
	return(path);
}
int check_accecs_exec(char *joined_path)
{
	int acc1;
	int acc2;
	acc1 = access(joined_path, F_OK);
	acc2 = access(joined_path, X_OK);
	if(acc1 == 0 && acc2 == 0)
		return(1);
	return(0);
}
char *join_get_acces(char **splited_path, char *cmd)
{
	int i;
	i = 0;
	//char *path_name;
	char *tmp;
	while(splited_path[i])
	{
		tmp = ft_strdup(splited_path[i]);
		free(splited_path[i]);
		splited_path[i] = ft_concatenate(tmp, "/", cmd);
		free(tmp);
		if(check_accecs_exec(splited_path[i]))
			return(ft_strdup(splited_path[i]));
		i++;
	}
	return(NULL);
}
void execve_cmd(t_command *command, t_env **env, char **argv)//command->argv:paramt3
{
    char *path;
	char **env1;
    path = execute_cmd(command, env);
	if(!path)
		return ;
	env1 = convertto_doublep(*env);
    if(execve(path, argv, env1) == -1)
        perror("Minishell: error: ");
    free(path);
}

// void execution(t_command *command, t_env **env)
// {
// 	if (command->type = PIPE)
// 		 exec_pipe();
// 	else
// 	{
// 		if (command->type == HERDOC|| command->type == SUP
// 			|| command->type == INF ||command->type = ADD)
// 				handle_redirection();
// 		else if (command->type == CMD)
// 			check_cmd(command, env);
// 	}
// }
void check_cmd(t_command *command, t_env **envv)
{
	if(check_builtings(command))
		is_builting(command, envv);
	else
		execve_cmd(command, envv, command->args);
}