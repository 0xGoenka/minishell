/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:31:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 19:06:36 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin(char **env, char **param)
{
	if (ft_strcmp(param[0], "env") == 0)
	{
		envcmd(param);
		return (1);
	}
	if (ft_strcmp(param[0], "cd") == 0)
	{
		cd_cmd(param);
		return (1);
	}
	return (0);
}

int		envcmd(char **param)
{
	extern char **environ;
	int i;

	i = 0;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
	return (1);
}

int		cd_cmd(char **param)
{
	extern char **environ;
	char		*pwd;

	if (tab_len(param) == 1)
	{
		pwd = get_home_dir();
		chdir(pwd);
		ft_strdel(&pwd);
	}
	else if (tab_len(param) == 2)
	{
		if (chdir(param[1]) != 0)
			ft_putendl("cd : no such file or directory");
	}
	else
		ft_putendl("cd : too many arguments.");
	return (1);
}
