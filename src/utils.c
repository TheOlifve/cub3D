/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:06:05 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/11 00:07:55 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**read_file(int fd, char *file)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	**ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit(3);
	tmp2 = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp3 = ft_strjoin(tmp2, tmp);
		free(tmp2);
		tmp2 = ft_strdup(tmp3);
		free(tmp3);
		free(tmp);
	}
	ret = ft_split(tmp2, '\n');
	free(tmp2);
	if (ret[0] == NULL)
		err_exit(4);
	return (ret);
}

void	doublefree(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	rgbtoi(char	*color)
{
	int		r;
	int		g;
	int		b;
	char	**spl;

	spl = ft_split(color, ',');
	r = ft_atoi(spl[0]) * (256 * 256);
	g = ft_atoi(spl[1]) * 256;
	b = ft_atoi(spl[2]);
	doublefree(spl);
	return (r + g + b);
}

void	mapSize(t_game *game)
{
	game->mapH = 0;
	game->mapW = 0;
	if (game->map && game->map[0])
		while (game->map[0][game->mapW])
			game->mapW++;
	while (game->map && game->map[game->mapH])
		game->mapH++;
}
