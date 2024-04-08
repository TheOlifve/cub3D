/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveRight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:29:31 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 10:48:16 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	checkRight(t_game *game)
{
	int	y;

	y = (game->pl->lY + playerSize) / pxlSize;
	if (game->map[game->pl->lX / pxlSize][y] != '1')
		;
	else
		return (0);
	if (game->map[(game->pl->lX + playerStep) / pxlSize][y] != '1')
		return (1);
	return (0);
}

void	moveRight(t_game *game, t_mlx *mlx)
{
	int	i;
	int	j;

	if (checkRight(game))
		game->pl->lY += playerStep;
	else
		return ;
	i = 0;
	while (i < playerSize)
	{
		j = 0;
		while (j < playerSize)
		{
			if (j < playerStep)
				mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j - playerStep, game->pl->lX + i, 0);
			mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX + i, 16711680);
			j++;
		}
		i++;
	}
}
