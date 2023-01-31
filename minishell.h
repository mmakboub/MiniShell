/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:08:18 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 12:05:46 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PIPE 0
# define INF 1
# define SUP 2
# define ADD 3
# define HERDOC 4
# define CMD 5
# define SQUOT 6
# define DQUOT 7

# include "Libft/libft.h"
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

typedef struct s_garbage_collector
{
	void						*memory;
	struct s_garbage_collector	*next;
}								t_garbage;

typedef struct s_global
{
	int							exit_status;
	int							exit_heredoc;
	int							sig;
	t_garbage					*temp;
	t_garbage					*end;
}								t_global;

extern t_global					g_global;

typedef struct s_env
{
	char						*value;
	char						*name;
	struct s_env				*next;
}								t_env;

typedef struct element
{
	int							type;
	int							space;
	int							nbr_args;
	char						**args;
	char						*cmd;
	int							pip[2];
	struct element				*next;
	struct element				*prev;
}								t_element;

typedef struct s_varpipe
{
	int		fd[2];
	int		i;
	int		argc;
	char	**envv;
	int		in_tmp;
	pid_t	pid;
}	t_pipe;

typedef struct s_args
{
	int			pid;
	int			argc;
	int			*fd;
	char		**envv;
	t_env		**env;
	t_element	*node;
	int			i;
}	t_args;

t_element						*tokeniser(char *line);
t_element						*parser(char *line, char **env);
t_element						*last(t_element *s);
int								grammar(t_element *s, char **env);
char							*add(char **str, char *s);
t_element						*norm_one(t_element *el);
void							expender(t_element *s, char **env);
void							delete_quote(t_element *s);
void							printferror(char *str);
int								check_is_digit(int x);
int								check_special_caract(char *arg);
t_env							*identique_var(char *arg, t_env **variable);
void							unset(t_env **variable, t_element *command);
void							pwd(t_env *env, char *name);
void							ft_exit(t_element *command);
long							check_exit_status(char *str);
void							export(t_env **env, t_element *command);
void							display_env(t_env **envt);
int								check_builtings(t_element *command);
void							is_builting(t_element *cmd, t_env **envv);
void							echo2(char **arg);
void							print_echoarg(char **arg);
int								check_echo_n(char *arg);
void							cd(t_element *command, t_env **env);
void							checkhome(t_env *pwd, t_env *oldpwd, \
t_env **env);
void							refresh_oldpwd(t_env **env, t_env *pwd);
t_env							*finder_getter(t_env *env, char *name);
char							*ft_substr(char const *s, unsigned int start, \
size_t len, int type);
char							*receive_name(char *allstr);
char							*receive_name_export(char *allstr);
char							*receive_value(char *allstr);
t_env							*ft_lstnew(char *allstr, int flag);
void							ft_lstadd_back(t_env *new, t_env **alst);
t_env							*build_env(char **env);
void							refresh_pwd(t_env **env);
void							ft_lstadd_back(t_env *new, t_env **alst);
void							env_initialisation(t_env **env);
char							*receive_value_export(char *allstr);
t_env							*env_finder(t_env *env, char *name);
void							printf_env(t_env **env);
int								check_plus(char *str, char c, char x);
int								check_caract(char *str, char c);
void							handle_pipe(t_element *node, t_env **env);
void							check_arg(t_element *command);
void							ft_env2(t_env *env, t_element *command);
void							ft_remove_from_env(t_env **begin_list, \
t_env *data_ref);
t_env							*env_finder(t_env *env, char *name);
t_env							*exportnameonly(t_element *command);
void							execve_cmd(t_element *command, t_env **env, \
char **argv);
char							*join_get_acces(char **splited_path, char *cmd);
int								check_accecs_exec(char *joined_path);
char							**convertto_doublep(t_env *env);
int								ft_lstsize_env(t_env *lst);
char							*convertto_char(t_env *env);
char							*ft_concatenate(const char *s1, const char *s2, \
const char *s3);
void							check_cmd(t_element *command, t_env **envv);
int								ft_isdigit(int x);
int								ft_strcmp(const char *s1, const char *s2);
int								ft_lstsize_elem(t_element *lst);
int								getsize(char **str);
int								check_rest_error(int type, int next);
int								handle_redirection(t_element *red, int i);
void							check_cd(t_element *command);
int								check_error(int type, int next);
void							herdoc(t_element *s, char **env);
char							*insert(char *str, int index, char *s, int sz);
char							*takevarvalue(char *str, char **env);
void							all_lower(char *cmd);
void							add_back(t_element **node, char *str, int type, \
int len);
void							str_tokeniser(char **str, t_element **elmnt, \
int *len);
int								issep(char c, char *sep);
void							squote_tokeniser(char **str, t_element **elmnt, \
int *len);
void							redir_tokeniser(char **str, t_element **elmnt, \
int *len);
char							*put_my_shlvl(char *str);
void							sig_default(void);
void							ignsig(void);
void							norm_two(t_element **el);
t_env							*sort_env(t_env *env);
int								check_is_valid(char *str);
void							path_error(char *cmd);
void							execve_cmd(t_element *command, \
t_env **env, char **argv);
void							execve_cmd_error(char *path, \
t_element *command);
void							execve_failure(char *cmd);
void							check_empty_export(char *str);
void							add_back_memory(void *mem, int i);
void							free_memory(int i);
char							*ft_substr(char const *s, unsigned int start, \
size_t len, int type);
char							**ft_split(char const *s, char c);
char							*ft_strdup(const char *s1, int type);
char							*ft_strjoin(const char *s1, const char *s2, \
int type);
char							*ft_itoa(int n, int type);
void							*ft_malloc(size_t len, int type);
int								readline_hook(void);
void							cd22(t_element *command, t_env **env);
void							back_to_home(t_env **env, t_env *oldpwd);
char							*concat(char *s1, char *s2);
char							**ft_concat(char **s1, char **s2);
void							add_node_back(t_element **node, t_element *el);
char							**double_dup(char **s);
void							handle_exit_status(int pid, t_element *command);
char							*join_get_acces(char **splited_path, char *cmd);
int								check_accecs_exec(char *joined_path);
char							*execute_cmd(t_element *command, t_env **env);
bool							check_relative_or_absolut(char *cmd, char c);
void							check_empty_export(char *str);
void							dup_0(int i, int argc, int fd[2]);
void							dup_1(int in_tmp, int fd[2], int pid, int argc);
void							lineisempty(char *line);
void							handling_sig(void);
int								readline_hook(void);
void							handler(int signum);
void							ignsig(void);
void							sig_default(void);
int								event(void);
int								ft_putchar(int c);

#endif