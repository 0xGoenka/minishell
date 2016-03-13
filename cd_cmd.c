/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:13:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/13 18:50:23 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_ext(t_lst *lst)
{
	char			**env;
	char			*tmp;
	char			buf[MAXPATHLEN + 1];
	int				i;
	int				j;

	env = lst_to_tab(lst->next);
	i = 0;
	j = 0;
	ft_bzero(buf, MAXPATHLEN + 1);
	while (env[i] && ft_strncmp(env[i], "PWD=", 4) != 0)
		i++;
	while (env[j] && ft_strncmp(env[j], "OLDPWD=", 7) != 0)
		j++;
	if (env[i] && ft_strncmp(env[i], "PWD=", 4) == 0 &&
	ft_strncmp(env[j], "OLDPWD=", 7) == 0)
	{
		tmp = ft_strsub(env[i], 4, ft_strlen(env[i]) - 4);
		env[j] = ft_strjoin("OLDPWD=", tmp);
		getcwd(buf, MAXPATHLEN);
		env[i] = ft_strjoin("PWD=", buf);
		fill_list("OLDPWD", env[j], lst->next);
		fill_list("PWD", env[i], lst->next);
	}
	return (1);
}

int		setenv_ext(t_lst *lst, char *name, char *content)
{
	t_lst *begin;

	begin = lst;
	lst = lst->next;
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
		{
			lst->content = ft_strdup(content);
			lst = begin;
			return (1);
		}
		lst = lst->next;
	}
	lst = begin;
	add(lst, name, content);
	return (1);
}
