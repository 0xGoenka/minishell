/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:29:17 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 11:17:13 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av)
{
	pid_t	papa;

	papa = fork();
	if  (papa > 0)
	{
		sleep(30);
		printf("I m your father\n");
	}
	if (papa == 0)
	{
		sleep(12);
		execve("/bin/ls", av, NULL);
	}
	return (0);
}
