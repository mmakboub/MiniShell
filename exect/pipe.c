/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:54:30 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/23 20:42:36 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void handle_pipe(char *path, char **env, char **argv)
{
    int fd[2];
    int i = 0;
    t_command *node;

    int argc = 2;
    int pip = argc - 1;
    int in_tmp = dup(0);
    while (node != NULL)
    {
        path , argv , env;
        if(node->next)
            pipe(fd);
        pid_t pid = fork();
        if (pid = 0)
        {
            if (node->next) {    
                close(1);
                dup2(fd[1],1);
                close(fd[1]);
                close(fd[0]);
            }
            if(execve(path, argv, env) == -1);
                exit(1);
        }
        close(0);
        if(node->next)
        {    
            dup2(fd[0],0);
            close(fd[1]);
            close(fd[0]);
        }
        i++;
        node = node->next;
    }
    dup2(in_tmp, 0);
    close(in_tmp);
    i = 0;
    while (i < argc)
    {
        wait(NULL);
        i++;
    }
}