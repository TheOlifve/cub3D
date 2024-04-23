/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:49:41 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/13 11:42:38 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	no_texture(t_mlx *mlx, t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(game->tmp[0], ' ');
	if (ft_strcmp(tmp[0], "NO") || valid_texture(tmp[1]))
	{
		doublefree(tmp);
		err_print(5);
		write(2, game->tmp[0], ft_strlen(game->tmp[0]));
		write(2, "\nRight form: NO ./path_to_the_north_texture\n", 45);
		return (1);
	}
	game->NO = mlx_xpm_file_to_image(mlx->pMlx, tmp[1], &i, &j);
	doublefree(tmp);
	return (0);
}

int	so_texture(t_mlx *mlx, t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(game->tmp[1], ' ');
	if (ft_strcmp(tmp[0], "SO") || valid_texture(tmp[1]))
	{
		doublefree(tmp);
		err_print(5);
		write(2, game->tmp[1], ft_strlen(game->tmp[1]));
		write(2, "\nRight form: SO ./path_to_the_south_texture\n", 45);
		return (1);
	}
	game->SO = mlx_xpm_file_to_image(mlx->pMlx, tmp[1], &i, &j);
	doublefree(tmp);
	return (0);
}

int	we_texture(t_mlx *mlx, t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(game->tmp[2], ' ');
	if (ft_strcmp(tmp[0], "WE") || valid_texture(tmp[1]))
	{
		err_print(5);
		write(2, game->tmp[2], ft_strlen(game->tmp[2]));
		write(2, "\nRight form: WE ./path_to_the_west_texture\n", 45);
		doublefree(tmp);
		return (1);
	}
	game->WE = mlx_xpm_file_to_image(mlx->pMlx, tmp[1], &i, &j);
	doublefree(tmp);
	return (0);
}

int	ea_texture(t_mlx *mlx, t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(game->tmp[3], ' ');
	if (ft_strcmp(tmp[0], "EA") || valid_texture(tmp[1]))
	{
		err_print(5);
		write(2, game->tmp[3], ft_strlen(game->tmp[3]));
		write(2, "\nRight form: EA ./path_to_the_east_texture\n", 45);
		doublefree(tmp);
		return (1);
	}
	game->EA = mlx_xpm_file_to_image(mlx->pMlx, tmp[1], &i, &j);
	doublefree(tmp);
	return (0);
}

int	textures_init(t_mlx *mlx, t_game *game)
{
	if (no_texture(mlx, game))
		return (1);
	if (so_texture(mlx, game))
		return (1);
	if (we_texture(mlx, game))
		return (1);
	if (ea_texture(mlx, game))
		return (1);
	return (0);
}