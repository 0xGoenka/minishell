/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:41:40 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/09 21:04:28 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void 	delelem(t_lst *lst, char *name)
{
	t_lst *tmp;
	t_lst *begin;

	begin = lst;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		ft_putendl(name);
		ft_putendl(lst->name);
		if (ft_strcmp(name, lst->name) == 0)
		{
			tmp->next = lst->next;
			//free(lst);
			lst = begin;
			return ;
		}
	}
	lst = begin;
	return ;
}
void fill_lst(t_lst *lst)
{
	char extern **environ;
	int i;
	char **split;

	i = 0;
	while (environ[i])
	{
		split = ft_strsplit(environ[i], '=');
		add(lst, split[0], environ[i]);
		i++;
	}
}
void		add(t_lst *lst, char *name, char *content)
{
	while (lst->next != NULL)
		lst = lst->next;
	if (!(lst->next = malloc(sizeof(t_lst))))
		return ;
	lst = lst->next;
	lst->next = NULL;
	lst->name = ft_strdup(name);
	lst->content = ft_strdup(content);
}

t_lst		*init(void)
{
	t_lst *lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
	return (lst);
}

void		lstdel(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

int			countlst(t_lst *lst)
{
	int i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void 		print(t_lst *lst)
{
	if (!lst)
		return ;
	ft_putendl(lst->content);
	print(lst->next);
}
