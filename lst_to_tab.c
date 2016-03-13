/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:00:58 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/10 11:32:52 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_tab(t_lst *lst)
{
	int		i;
	char	**ret;
	t_lst	*begin;

	begin = lst;
	ret = (char **)malloc(sizeof(char *) * countlst(lst) + 1);
	i = 0;
	while (lst)
	{
		ret[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	ret[countlst(begin)] = NULL;
	return (ret);
}

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
