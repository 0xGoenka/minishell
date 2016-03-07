/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:29:39 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 18:57:49 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>

int			asacces(char *exec);
int			basicexec(char *exec, char **param);
int			basic_exec(char **param, char **path);
int			controller(char *in);
int			exec_bin(char **param, char **path);

char		**split_path(void);
int			tab_len(char **tab);
int			is_exec(char **param);
char	*get_home_dir(void);

int			builtin(char **path, char **param);
int			envcmd(char **param);
int			cd_cmd(char **param);

typedef struct	s_env
{
	char		*path;
	char		*tmpdir;
	char		*logname;
	char		*xpc_flags;
	char		*home;
	char		*pwd;
	char		*oldpwd;
}				t_env;

#endif
