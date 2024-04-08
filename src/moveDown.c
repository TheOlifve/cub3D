/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveDown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:27:18 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/07 21:27:55 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	checkDown(t_game *game)
{
	int	x;

	x = (game->pl->lX + playerSize) / pxlSize;
	if (game->map[x][game->pl->lY / pxlSize] != '1')
		;
	else
		return (0);
	if (game->map[x][(game->pl->lY + playerStep) / pxlSize] != '1')
		return (1);
	return (0);
}

void	moveDown(t_game *game, t_mlx *mlx)
{
		int	i;
	int	j;

	if (checkDown(game))
		game->pl->lX += playerStep;
	else
		return ;
	i = 0;
	while (i < playerSize)
	{
		j = 0;
		while (j < playerSize)
		{
			if (i < playerStep)
				mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX - playerStep + i, 0);
			mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX + i, 16711680);
			j++;
		}
		i++;
	}
}
