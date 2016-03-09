/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:29:39 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/09 21:21:20 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>

typedef struct  	s_lst
{
	char			*name;
	char			*content;
	struct s_lst 	*next;
}					t_lst;

int					asacces(char *exec);
int					basicexec(char *exec, char **param, t_lst *lst);
int					basic_exec(char **param, char **path, t_lst *lst);
int					controller(char *in, t_lst *lst);
int					exec_bin(char **param, char **path, t_lst *lst);

char				**split_path(t_lst *lst);
int					tab_len(char **tab);
int					is_exec(char **param);
char				*get_home_dir(void);

int					builtin(char **path, char **param, t_lst *lst, char *in);
int					envcmd(char **param, t_lst *lst);
int					cd_cmd(char **param);
int					setenv_cmd(char **param, t_lst *lst, char *in);
int					unsetenv_cmd(char **param, t_lst *lst);

int					cd_ext(char *pwd);

char				**lst_to_tab(t_lst *lst);

void 				fill_lst(t_lst *lst);
void				add(t_lst *lst, char *name, char *content);
t_lst				*init(void);
void				lstdel(t_lst *lst);
int					countlst(t_lst *lst);
void 				print(t_lst *lst);
void 				delelem(t_lst *lst, char *name);
void 	print_tab(char **tab);

typedef struct		s_env
{
	char			*path;
	char			*tmpdir;
	char			*logname;
	char			*xpc_flags;
	char			*home;
	char			*pwd;
	char			*oldpwd;
}					t_env;

#endif
