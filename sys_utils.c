/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:38:43 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/09 21:28:02 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(t_lst *lst)
{
	char 		**path;
	char 		*tmp;
	char 		**env;
	int i;

	i = 0;
	env = lst_to_tab(lst->next);
	while (env[i] && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	if (env[i] && ft_strncmp("PATH=", env[i], 5) == 0)
	{
		tmp = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
		path = ft_strsplit(tmp, ':');
		free(tmp);
		return (path);
	}
	else
		return (0);

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
	int i;

	homepath = NULL;
	i = 0;
	while (environ[i] && ft_strncmp("HOME=", environ[i], 5) != 0)
		i++;
	if (environ[i] && ft_strncmp("HOME=", environ[i], 5) == 0)
		homepath = ft_strsub(environ[i], 5, ft_strlen(environ[i]) - 5);
	return (homepath);
}
