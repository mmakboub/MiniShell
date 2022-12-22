char *execute_cmd(t_command *command)
{
	char *line;
	char *path;
	char **splited_path;
	int i;

	// if((command->cmd[0][0] == '.' && command->cmd[0][1] == '/') ||  command->cmd[0][0] == '/')
	// 	run_executable(command);//todo
	line = getenv("PATH");
	if(!line)
		return(NULL);
	splited_path = ft_split(&line, ':');
	if(!splited_path)
		return(NULL);
	path = join_get_acces(splited_path, command->cmd);
    if (!path)
		path = command->cmd;
	return(path);
}
int check_acces(char *joined_path)
{
	int acc1;
	int acc2;
	acc1 = access(joined_path, F_OK);
	acc2 = access(joined_path, X_OK);
	if(acc1 == 0 && acc2 == 0)
		return(1);
	retur(0);
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
		if(!check_accecs(splited_path[i]));
			return(NULL);//don't knw what should i do in this case : todo: should fixe it;
		return(ft_strdup(splited_path));
	}
}
void execve_cmd(t_command *command, char **env, char **argv)//command->argv:paramt3
{
    char *path;
    char *msg_error;
    path = execute_cmd(command);//todo : adding variable that stores all environment informatin
    if(execve(path, argv, env) == -1)
        perror("Minishell: error: ");
    free(path);
    //todo:free env;
}