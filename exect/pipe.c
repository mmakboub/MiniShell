/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:54:30 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 18:26:15 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void handle_pipe(t_command *node, t_env **env)
{
    int fd[2];
    int i = 0;
    int result = EXIT_SUCCESS;
    // t_command *node;

    int argc = 3;
    // int pip = argc - 1;
    int in_tmp = dup(0);   
    while (node != NULL)
    {
        if(node->next)
        {
            if (pipe(fd) == -1)
            {
                printf("lol\n");
                exit(1);
            }
        }
        pid_t pid = fork();
        if (pid == 0)
        {
            if (node->next) {
                if (dup2(fd[1],1) == -1)
                {
                    perror("lol1");
                }
                close(fd[1]);
                close(fd[0]);
            }
            // if (check_builtin(node) == 1)
		    //     is_builting(node, env);
            check_cmd(node, env);
	        if (result == EXIT_FAILURE)
		        printf("command not found");
        }
        // dup2(in_tmp, 0);
        if (node->next)
        {
            if (dup2(fd[0],0) == -1)
            {
                perror("lol2");
            }
            close(fd[1]);
            close(fd[0]);
        }
        i++;
        node = node->next;
    }
    dup2(in_tmp, 0);
    close(in_tmp);
    close(fd[0]);
    close(fd[1]);
    i = 0;
    while (i < argc)
    {
        wait(NULL);
        i++;
    }
}

