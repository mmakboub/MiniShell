/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:23:17 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 16:22:19 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include"libft/libft.h"
 #include <errno.h>

#define PIPE 0
#define INF 1
#define SUP 2
#define ADD 3
#define HERDOC 4
#define CMD 5
#define SQUOT 6
#define DQUOT 7
typedef struct s_env
{
    char *value;
    char *name;
    struct s_env *next;
}   t_env;
typedef struct s_command{
    int type;
    int space;
    char **args;
    char *cmd;
    int nbr_args;
    struct s_command *next;
    struct s_command *prev;
}   t_command;


void    printferror(char *str);
int     check_is_digit(int x);
int     check_special_caract(char *arg);
t_env   *identique_var(char  *arg, t_env **variable);
void    unset(t_env **variable ,t_command *command);
void    pwd(void);
void    ft_exit(t_command *command);
long    check_exit_status(char *str);
void    export(t_env **env, t_command *command);
void    display_env(t_env **envt);
void	check_builtings(t_command **command);
void	is_builting(t_command *cmd, t_env **envv);
void    echo(char **arg);
void    print_echoarg(char **arg);
int     check_echo_n(char *arg);
void    cd(t_command *command, t_env **env);
void    checkhome(t_env *pwd, t_env *oldpwd, t_env **env);
void	refresh_oldpwd(t_env	**env, t_env *pwd);
t_env	*finder_getter(t_env	*env, char *name);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *receive_name(char *allstr);
char *receive_name_export(char *allstr);
char    *receive_value(char *allstr);
t_env	*ft_lstnew(char *allstr, int flag);
void	ft_lstadd_back(t_env *new, t_env **alst);
t_env   *build_env(char **env);
void	refresh_pwd(t_env **env);
void	ft_lstadd_back(t_env *new, t_env **alst);
void    env_initialisation(t_env **env);
char    *receive_value_export(char *allstr);
t_env	*env_finder(t_env	*env, char *name);
void	printf_env(t_env **env);
int     check_plus(char *str, char c, char x);
int     check_caract(char *str, char c);
void    handle_pipe(t_command *node , char *path1,  char *path2, char *path3 , char **env, char **argv1, char **argv2, char **argv3);
void	check_arg(t_command *command);
void    ft_env2(t_env *env, t_command *command);
void    ft_remove_from_env(t_env **begin_list, t_env *data_ref);
t_env   *env_finder(t_env	*env, char *name);
t_env    *exportnameonly(t_command *command);
#endif