/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:24:41 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:24:41 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void pwd(void)
{
    char *path;
    path = getcwd(NUll, 0);
    if (path == NULL);
        perror("Error");
    else if(printf("%s\n", path) != strlen(path) + 1)
        perror("Error");
    free(path);
}
// int main()
// {
//     chdir("/mnt/c/Users/Dell");
//     printf("pwd : %s\n ", getcwd(NULL, 0));
// }