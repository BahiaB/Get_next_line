/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:33:37 by bbenali           #+#    #+#             */
/*   Updated: 2020/01/22 16:00:00 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		ft_check(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *line, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	j = i;
	i++;
	while (line[i])
		*str++ = line[i++];
	if (j == 0)
	{
		free(line);
		line = ft_strdup("");
	}
	else
		while (line[j])
		{
			line[j] = 0;
			j++;
		}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	str[BUFFER_SIZE];

	if (!(line) || fd < 0 || buf <= 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_check(str) == 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
	}
	*line = ft_strdup(str);
	ft_bzero(str, BUFFER_SIZE);
	while (ft_check(*line) == 0)
	{
		*line = ft_strjoin(*line, buf);
		ft_bzero(buf, (BUFFER_SIZE + 1));
		if ((ft_check(*line) == 0) && ((ret = read(fd, buf, BUFFER_SIZE)) <= 0))
			return (0);
		buf[ret] = '\0';
	}
	ft_bzero(buf, (BUFFER_SIZE + 1));
	*line = ft_get_line(*line, str);
	return (1);
}
