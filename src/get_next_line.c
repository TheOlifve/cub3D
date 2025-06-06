/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:59:44 by rugrigor          #+#    #+#             */
/*   Updated: 2024/04/08 20:46:14 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*strn(char *ptr)
{
	int		i;
	char	*pa;

	i = 0;
	while (ptr && ptr[i] && ptr[i] != '\n')
		i++;
	pa = ft_substr(ptr, 0, i + 1);
	return (pa);
}

char	*strn2(char *ptr)
{
	int		i;
	char	*pa;

	i = 0;
	while (ptr && ptr[i] && ptr[i] != '\n')
		i++;
	pa = ft_substr(ptr, i + 1, ft_strlen(ptr) - i + 1);
	free(ptr);
	ptr = ft_strdup(pa);
	free(pa);
	pa = (NULL);
	return (ptr);
}

static char	*go_go(char *buff, int fd, char *str)
{
	int		i;
	char	*pa;

	if (ft_strchr(str, '\n'))
		return (str);
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		if (!str)
			str = ft_strdup("");
		pa = ft_strdup(str);
		free(str);
		str = ft_strjoin(pa, buff);
		free(pa);
		pa = (NULL);
		if (ft_strchr(str, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	str = go_go(buff, fd, str);
	ptr = strn(str);
	free(buff);
	buff = NULL;
	if (!str)
		return (NULL);
	str = strn2(str);
	if (*ptr == 0)
	{
		free(str);
		str = (NULL);
		free(ptr);
		ptr = (NULL);
		return (NULL);
	}
	return (ptr);
}
