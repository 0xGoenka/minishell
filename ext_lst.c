/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:29:49 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/10 13:40:49 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		countlst(t_lst *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print(t_lst *lst)
{
	if (!lst)
		return ;
	ft_putendl(lst->content);
	print(lst->next);
}

void	fill_list(char *name, char *content, t_lst *lst)
{
	int			i;

	i = 0;
	while (lst->next)
	{
		if (ft_strcmp(lst->name, name) == 0)
		{
			lst->content = ft_strdup(content);
			return ;
		}
		lst = lst->next;
	}
}

char	*ret_content(char *name, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
			return (lst->content);
		lst = lst->next;
	}
	return (0);
}

void	checkhome(char **param, t_lst *lst)
{
	int		i;
	char	*tmp;
	char	*home;

	home = ret_content("HOME", lst->next);
	i = 0;
	while (param[i])
	{
		if (param[i][0] == '~')
		{
			if (!home)
			{
				param[i] = param[i] + 1;
				return ;
			}
			tmp = ft_strjoin(home + 5, param[i] + 1);
			param[i] = tmp;
		}
		i++;
	}
}
