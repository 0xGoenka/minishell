/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:29:39 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 12:00:42 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_env
{
	char *path;
	char *tmpdir;
	char *logname;
	char *xpc_flags;
	char *home;
	char *pwd;
	char *oldpwd;
}				t_env;

#endif
