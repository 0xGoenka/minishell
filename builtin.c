/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:31:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/13 18:50:46 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin(char **param, t_lst *lst)
{
	if (ft_strcmp(param[0], "env") == 0)
	{
		envcmd(lst);
		return (1);
	}
	if (ft_strcmp(param[0], "cd") == 0)
	{
		cd_cmd(param, lst);
		return (1);
	}
	if (ft_strcmp(param[0], "setenv") == 0)
	{
		setenv_cmd(param, lst);
		return (1);
	}
	if (ft_strcmp(param[0], "unsetenv") == 0)
	{
		unsetenv_cmd(param, lst);
		return (1);
	}
	if (ft_strcmp(param[0], "exit") == 0)
		return (0);
	return (-1);
}

int		envcmd(t_lst *lst)
{
	int		i;

	i = 0;
	print(lst->next);
	return (1);
}

int		setenv_cmd(char **param, t_lst *lst)
{
	char **split;

	if (tab_len(param) == 2 && check(param[1]))
	{
		split = ft_strsplit(param[1], '=');
		if (split[0] && param[1][0] != '=')
			setenv_ext(lst, split[0], param[1]);
		else
		{
			ft_putendl("setenv : usage [setenv var=abcdefgh]");
			return (1);
		}
		free(split);
	}
	else
		ft_putendl("setenv : usage [setenv var=abcdefgh]");
	return (1);
}

int		unsetenv_cmd(char **param, t_lst *lst)
{
	int i;

	i = 1;
	if (tab_len(param) == 1)
		ft_putendl("unsetenv : usage [unsetenv name1 name2 ..]");
	else
	{
		while (param[i])
		{
			delelem(lst, param[i]);
			i++;
		}
	}
	return (1);
}

int		cd_cmd(char **param, t_lst *lst)
{
	char		*pwd;

	if (tab_len(param) == 1)
	{
		pwd = get_home_dir(lst);
		cd_ext(lst);
		chdir(pwd);
		ft_strdel(&pwd);
	}
	else if (tab_len(param) == 2)
	{
		if (chdir(param[1]) != 0)
			ft_putendl("cd : no such file or directory");
		else
			cd_ext(lst);
	}
	else
		ft_putendl("cd : too many arguments.");
	return (1);
}
