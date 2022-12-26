/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:57:46 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/26 12:16:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"
char *execute_cmd(t_command *command)
{
	char *line;
	char *path;
	char **splited_path;
	int i;
	if(!check_accecs_exec(command->cmd));//todo : ADD another fonction that check only accessibility while the path is executable and replace it in this line (nammed :check_access)
		path = command->cmd;
	line = getenv("PATH");
	if(!line)
		return(NULL);
	splited_path = ft_split(&line, ':');
	if(!splited_path)
		return(NULL);
	path = join_get_acces(splited_path, command->cmd);
    if (!path)
		return(NULL);
	return(path);
}
int check_acces_exec(char *joined_path)
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
		if(check_accecs_exec(splited_path[i]));
			return(ft_strdup(splited_path[i]));
		i++;
	}
	return(NULL);
}
void execve_cmd(t_command *command, char **env, char **argv)//command->argv:paramt3
{
    char *path;
    path = execute_cmd(command);
    if(execve(path, argv, env) == -1)
        perror("Minishell: error: ");
    free(path);
}

void execution(t_command *command, t_env **env)
{
	int		fd[2];
	
	fd[1] = dup(1);
	fd[0] = dup(0);
	if (command->type = PIPE)
		 exec_pipe();
	else
	{
		if (command->type == HERDOC|| command->type == SUP
			|| command->type == INF ||command->type = ADD)
				handle_redirection();
		else if (command->type == CMD)
			check_cmd();
	}
}
void check_cmd(t_command *command, t_env **envv)
{
	if(check_builtings)
		is_builting(command, envv);
	else
		execve_cmd(command, envv, command->args)
		
}