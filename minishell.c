/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:15:13 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/13 18:50:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char	*in;
	t_lst	*lst;
	char	path[MAXPATHLEN + 1];

	lst = init();
	fill_lst(lst);
	while (42)
	{
		ft_bzero(path, MAXPATHLEN + 1);
		getcwd(path, MAXPATHLEN);
		ft_putstr(path);
		ft_putstr(" ###> ");
		if (get_next_line(0, &in) == 1)
		{
			if (!controller(in, lst))
			{
				lstdel(lst);
				return (0);
			}
		}
	}
	return (0);
}

int		controller(char *in, t_lst *lst)
{
	char	**path;
	char	**param;
	int		ret;

	path = split_path(lst);
	param = split_advanced(in, ' ', '	');
	checkhome(param, lst);
	if (!param[0])
		return (1);
	if (!(ret = builtin(param, lst)))
		return (0);
	if (ret == 1)
		return (1);
	if (basic_exec(param, lst))
		return (1);
	if (exec_bin(param, path, lst))
		return (1);
	return (1);
}

int		basic_exec(char **param, t_lst *lst)
{
	pid_t	pid;
	int		status;
	int		i;
	char	**env;

	i = 0;
	env = lst_to_tab(lst->next);
	if (is_exec(param) == 0)
		return (0);
	if (param[0][0] == '.' || param[0][0] == '/')
	{
		if (access(param[0], X_OK) == 0)
		{
			pid = fork();
			if (pid > 0)
				waitpid(pid, &status, 0);
			if (pid == 0)
				execve(param[0], param, env);
			return (1);
		}
	}
	return (0);
}

int		exec_bin(char **param, char **path, t_lst *lst)
{
	pid_t	pid;
	int		status;
	int		i;
	char	*tmp;
	char	**env;

	i = 0;
	env = lst_to_tab(lst->next);
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp, param[0]);
		if (access(tmp, X_OK) == 0)
		{
			pid = fork();
			if (pid > 0)
				waitpid(pid, &status, 0);
			if (pid == 0)
				execve(tmp, param, env);
			return (1);
		}
		i++;
	}
	ft_putendl("shell : command not found");
	return (0);
}
