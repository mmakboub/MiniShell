/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:13 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/23 17:34:45 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    int **fd;
    int i = 0;

    int process = 2;
    int pip = process - 1;
    fd = (int **)malloc(sizeof(int *) * pip);
    while (i < pipe)
    {
        fd[i] = (int *)malloc(sizeof(int) * 2);
        if (pipe(fd[i]) == -1)
            return (1);
        i++;
    }
    i = 0;

    while (element != NULL)
    {
        path , argv , env;
        pid_t pid = fork();
        if (pid = 0)
        {
            if (i == 0)
            {
                dup2(fd[i][1], stdout);
            }
            else if ( i == process - 1)
            {
                dup2(fd[i - 1][0], stdin);
            }
            else
            {
                dup2(fd[i - 1][0], stdin);
                dup2(fd[i][1], stdout);
            }

            close_all(fd);
            if(execve(path, cmd, env) == -1);
                exit(1);
        }
        close(fd[i][1]);
        i++;
        element = element->next;
    }
    close_all(fd);
    i = 0;
    while (i < process)
    {
        wait(NULL);
        i++;
    }
}