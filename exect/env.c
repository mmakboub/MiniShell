

void env(t_env **cmd, t_command *command) //to do : add a condition if THERE IS MORE THAN 1 arg it should print to nmany args 
{
    t_env *tmp;
    tmp = cmd;
    if(command->nb_args > 1)
        printf("env: %s: No such file or directory\n", command->args[1]);
    else 
    {      
        while(tmp)
        {
            if(tmp->value)
            {
                printf("%s",tmp->name);
                write(1, '=', 1);
                printf("%s\n", tmp->value);
            }
        }
        tmp = tmp->next;
    }
}