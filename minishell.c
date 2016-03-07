/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:15:13 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 18:38:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main()
{
	char *in;
	char *t_env;

	while (42)
	{
		ft_putstr("<3 ?> ");
		if (get_next_line(0, &in))
		{
			if (!ft_strcmp(in, "exit"))
				return (0);
			controller(in);
		}
	}
	return (0);
}

int		controller(char *in)
{
	char **path;
	char **param;

	path = split_path();
	param = ft_strsplit(in, ' ');
	if (builtin(path, param))
		return (1);
	if (basic_exec(param, path))
		return (1);
	if (exec_bin(param, path))
		return (1);
	return (0);
}

int		basic_exec(char **param, char **path)
{
	pid_t pid;
	int status;
	int i;

	i = 0;

	if (is_exec(param) == 0)
		return (0);
	if (param[0][0] == '.' || param[0][0] == '/')
	{
		if (access(param[0], X_OK) == 0)
		{
			ft_putstr("Exec\n");
			pid = fork();
			if (pid > 0)
				waitpid(pid, &status, 0);
			if (pid == 0)
				execve(param[0], param, NULL);
			return (1);
		}
	}
	return (0);
}

int		exec_bin(char **param, char **path)
{
	pid_t pid;
	int status;
	int i;
	char *tmp;
	char *tmp2;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i],"/");
		tmp = ft_strjoin(tmp, param[0]);
		if (access(tmp, X_OK) == 0)
		{
			pid = fork();
			if (pid > 0)
				waitpid(pid, &status, 0);
			if (pid == 0)
				execve(tmp, param, NULL);
			return (1);
		}
		i++;
	}
	ft_putendl("shell : command not found");
	return (0);
}
