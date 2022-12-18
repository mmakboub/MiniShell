void checkhome(t_env **env)
{
    t_env *home;
    home = finder_getter(env, "HOME");
    if(!home)
    {
        printf("Minishell: cd: HOME not set");
        return;
    }
    if(chdir(home->value) == -1)
        perror("cd");

} 


void cd(t_command *command, t_env **env)
{
    t_env *pwd;
    t_env  *oldpwd;
    

    pwd = finder_getter(env, "PWD");
    oldpwd = finder_getter(env, "OLDPWD");
    if(!pwd || !oldpwd)
         return ;
    if((!strcmp(command->args[1]) ,"--") || !strcmp(command->args[1], "~") || command->nb_args == 1 || (command->args[1][0] == '#'))
        back_to_home(pwd, oldpwd, env);
    else if (command->nb_args > 1)
    {
        if(chdir(command->args[1]) == -1)
            perror("cd");
    }
    refresh_pwd(env, pwd);
    refresh_oldpwd(env);
}