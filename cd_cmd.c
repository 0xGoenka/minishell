/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:13:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/09 15:59:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/param.h>

int		cd_ext(char *pwd)
{
	extern char		**environ;
	char			*tmp;
	char			buf[MAXPATHLEN +1];
	int i;
	int j;

	i = 0;
	j = 0;
	ft_bzero(buf, MAXPATHLEN + 1);
	while (environ[i] && ft_strncmp(environ[i], "PWD=", 4) != 0)
		i++;
	while (environ[j] && ft_strncmp(environ[j], "OLDPWD=", 7) != 0)
		j++;
	if (environ[i] && ft_strncmp(environ[i], "PWD=", 4) == 0 &&
	ft_strncmp(environ[j], "OLDPWD=", 7) == 0)
	{
		tmp = ft_strsub(environ[i], 4, ft_strlen(environ[i]) - 4);
		environ[j] = ft_strjoin("OLDPWD=", tmp);
		free(tmp);
		getcwd(buf, MAXPATHLEN);
		environ[i] = ft_strjoin("PWD=", buf);
	}
	return (1);
}
