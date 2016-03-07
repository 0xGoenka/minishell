/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:46:57 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/07 11:29:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strchrendl(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	return (i);
}

static char		*split_and_copy(char **rest)
{
	char	*tmp;
	char	*value;
	char	*tmp2;

	tmp2 = ft_strdup(*rest);
	tmp = ft_strdup(ft_strchr(*rest, '\n'));
	value = ft_strsub(tmp2, 0, ft_strlen(tmp2) - ft_strlen(tmp));
	ft_strdel(rest);
	*rest = ft_strdup(tmp + 1);
	ft_strdel(&tmp2);
	ft_strdel(&tmp);
	return (value);
}

static char		*push_read(char *buf, char **rest, int j)
{
	char		*tmp;

	if (*rest != NULL && buf != NULL)
	{
		tmp = ft_strdup(*rest);
		ft_strdel(&(*rest));
		*rest = ft_strjoin(tmp, buf);
		ft_strdel(&(tmp));
	}
	else if (*rest == NULL && buf != NULL)
		*rest = ft_strdup(buf);
	if (*rest != NULL)
	{
		if (ft_strchr(*rest, '\n'))
			return (split_and_copy(rest));
		else if (j)
		{
			tmp = ft_strdup(*rest);
			ft_strdel(rest);
			return (tmp);
		}
	}
	return (NULL);
}

static int		ft_error(char **rest, char **line)
{
	if (ft_strchrendl(*rest) == 0)
		return (0);
	*line = ft_strdup(*rest);
	ft_strdel(rest);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	char		buf[BUFF_SIZE + 1];
	static char	*rest;

	if (fd < 0 || !line)
		return (-1);
	if ((*line = push_read(NULL, &rest, 0)))
		return (1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if ((*line = push_read(buf, &rest, (i < BUFF_SIZE))))
			return (1);
	}
	if (i < 0)
		return (-1);
	if (i == 0 && rest != NULL)
	{
		if ((ft_error(&rest, line) == 0))
			return (0);
		else
			return (1);
	}
	return (0);
}
