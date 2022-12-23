/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:13 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/23 20:19:02 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    int fd[2];
    int i = 0;
    t_element *element;

    int process = 2;
    int pip = process - 1;
    int in_tmp = dup(0);
    while (element != NULL)
    {
        path , argv , env;
        if(element->next)
            pipe(fd);
        pid_t pid = fork();
        if (pid = 0)
        {
            if (element->next) {    
                close(1);
                dup2(fd[1],1);
                close(fd[1]);
                close(fd[0]);
            }
            if(execve(path, cmd, env) == -1);
                exit(1);
        }
        close(0);
        if(element->next)
        {    
            dup2(fd[0],0);
            close(fd[1]);
            close(fd[0]);
        }
        i++;
        element = element->next;
    }
    dup2(in_tmp, 0);
    close(in_tmp);
    i = 0;
    while (i < process)
    {
        wait(NULL);
        i++;
    }
}