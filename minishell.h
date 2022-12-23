/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:23:17 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/23 22:38:55 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

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
    struct command *next;
    struct command *prev;
}   t_command;


void    printferror(char *str);
void    ft_remove_fron_env(t_env **begin_list, t_env *data_ref);
int     check_is_digit(int x);
int     check_special_caract(char **arg);
t_env   *identique_var(char  *arg, t_env **variable);
void    unset(t_env **variable ,t_command *command);
void    pwd(void);
void    exit(t_command *command);
int     check_exit_status(char *str);
void    export(t_command *command, t_env **env);
void    display_env(t_env **envt);
void	check_builtings(t_command **command);
void	is_builting(t_command *cmd, t_env **envv)
void    env(t_env **cmd, t_command *command);
void    echo(char **arg);
void    print_echoarg(char **arg);
int     check_echo_n(char *arg)
void    cd(t_command *command, t_env **env);
void    checkhome(t_env *pwd, t_env *oldpwd, t_env **env);
void	refresh_oldpwd(t_env	**env, char *pwd);
t_env	*finder_getter(t_env	*env, char *name);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char receive_name(char *allstr);
t_env	*ft_lstnew(char *allstr);
void	ft_lstadd_back(t_env *new, t_env **alst);
t_env   *build_env(char **env);
void	refresh_pwd(t_env **env);
#endif