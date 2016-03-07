/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:15:13 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 12:01:18 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main()
{
	char *in;
	char *t_env;

	t_en = fillenv();
	while (42)
	{
		ft_putstr("<3 ?> ");
		if (get_next_line(0, &in))
		{
			if (!ft_strcmp(in, "exit"))
				return (0);
			printf("acces = %d\n", access("/bin/ls", X_OK));
		}
	}
	return (0);
}
