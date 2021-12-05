/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:33:31 by bbenali           #+#    #+#             */
/*   Updated: 2020/01/22 13:55:47 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*s3;

	i = 0;
	k = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2 || !(s3 = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] && k < (unsigned int)ft_strlen(s1))
		s3[k++] = s1[i++];
	i = 0;
	while (s2[i] && k < (unsigned int)(ft_strlen(s2) + ft_strlen(s1)))
		s3[k++] = s2[i++];
	s3[k] = '\0';
	free(s1);
	return (s3);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}
