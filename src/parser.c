/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:41 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/07 12:46:21 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	mon(char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	if (!ft_strcmp(tmp[0], "NO") || !ft_strcmp(tmp[0], "SO")
		|| !ft_strcmp(tmp[0], "WE") || !ft_strcmp(tmp[0], "EA")
			|| !ft_strcmp(tmp[0], "F") || !ft_strcmp(tmp[0], "C"))
	{
		doublefree(tmp);
		return (0);
	}
	doublefree(tmp);
	return (1);
}

int	validElem(t_game *game)
{
	int	i;

	i = -1;
	while (game->params && game->params[++i])
		if (mon(game->params[i]))
			return (1);
	return (0);
}

void	paramSeparate(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp3 = ft_strdup("");
	i = -1;
	while(game->tmp && game->tmp[++i])
	{
		j = 0;
		while (game->tmp[i][j] && game->tmp[i][j] == ' ')
			++j;
		if (!mon(game->tmp[i]))
		{
			tmp = ft_strjoin(game->tmp[i], "\n");
			tmp2 = ft_strjoin(tmp3, tmp);
			free(tmp);
			free(tmp3);
			tmp3 = ft_strdup(tmp2);
			free(tmp2);
		}
	}
	game->params = ft_split(tmp3, '\n');
	free(tmp3);
}

void	mapSeparate(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp3 = ft_strdup("");
	i = -1;
	while(game->tmp && game->tmp[++i])
	{
		j = 0;
		while (game->tmp[i][j] && game->tmp[i][j] == ' ')
			++j;
		if (mon(game->tmp[i]))
		{
			tmp = ft_strjoin(game->tmp[i], "\n");
			tmp2 = ft_strjoin(tmp3, tmp);
			free(tmp);
			free(tmp3);
			tmp3 = ft_strdup(tmp2);
			free(tmp2);
		}
	}
	game->map = ft_split(tmp3, '\n');
	free(tmp3);
}

int	parser(t_mlx *mlx, t_game *game, char *file)
{
	(void)mlx;
	if (valid_file_type(file, ".cub"))
		return err_print(2);
	game->tmp = read_file(-1, file);
	if (game->tmp)
	{
		mapSeparate(game);
		paramSeparate(game);
	}
	if (validElem(game))
		return (err_print(6));
	// if (textures_init(mlx, game))
	// 	return (1);
	return (0);
}
	// int		i;

	// i = 0;
	// while (game->map && game->map[i])
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
	// printf("\n\n\n\n\n\n");
	// i = 0;
	// while (game->params && game->params[i])
	// {
	// 	printf("%s\n", game->params[i]);
	// 	i++;
	// }