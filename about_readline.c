/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:43:27 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/24 17:07:23 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
int main(int argc, char** argv) 
{
    while (1) 
    {
        char *prompt = "minishell > ";
        char *input = readline(prompt);
        printf("%s\n", input);
        free (input);
    }

  return 0;
}