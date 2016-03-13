/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:03:19 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/10 13:22:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strhelp(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * len + 1);
	while (start < len)
	{
		*str = s[start];
		start++;
		str = str + 1;
	}
	*str = '\0';
	return (str - len);
}

static int	ft_nb_mots(char const *s, char c, char d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] && s[i] == c) || (s[i] && s[i] == d))
			i++;
		while ((s[i] && s[i] != c) && (s[i] && s[i] != d))
			i++;
		if (s[i] != '\0' || (s[i - 1] != c && s[i - 1] != d))
			j++;
	}
	return (j);
}

char		**split_advanced(char const *s, char c, char d)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	l = ft_nb_mots(s, c, d);
	str = (char **)malloc(sizeof(char *) * l + 1);
	while (i < l)
	{
		j = 0;
		while ((*s && *s == c) || (*s && *s == d))
			s = s + 1;
		while ((*(s + j) && *(s + j) != c) && (*(s + j) && *(s + j) != d))
			j++;
		*(str++) = ft_strhelp(s, 0, j);
		s = s + j;
		i++;
	}
	*str = NULL;
	return (str - l);
}
