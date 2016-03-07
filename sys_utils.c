/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:38:43 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 19:01:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(void)
{
	char 		**path;
	char 		*tmp;
	extern char **environ;

	tmp = ft_strsub(environ[0], 5, ft_strlen(environ[0]) - 5);
	path = ft_strsplit(tmp, ':');
	free(tmp);
	return (path);
}
int		is_exec(char **param)
{

	if (!ft_strlen(param[0]))
		return (0);
	if (param[0][0] == '.' || param[0][0] == '/')
	{
		if (open(param[0], O_RDONLY) == -1)
		{
			ft_putstr("shell : no such file or directory : ");
			ft_putendl(param[0]);
			return (0);
		}
		if (opendir(param[0]))
		{
			ft_putstr("shell : permission denied : ");
			ft_putendl(param[0]);

			return (0);
		}
	}
	return (1);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*get_home_dir(void)
{
	extern char **environ;
	char		*homepath;

	homepath = ft_strsub(environ[4], 5, ft_strlen(environ[4]) - 5);
	return (homepath);
}
