/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveUp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:26:25 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/07 21:27:10 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	checkUp(t_game *game)
{
	int	x;

	x = (game->pl->lX - playerStep) / pxlSize;
	if (game->map[x][game->pl->lY / pxlSize] != '1')
		;
	else
		return (0);
	if (game->map[x][(game->pl->lY + playerStep) / pxlSize] != '1')
		return (1);
	return (0);
}

void	moveUp(t_game *game, t_mlx *mlx)
{
	int	i;
	int	j;

	if (checkUp(game))
		game->pl->lX -= playerStep;
	else
		return ;
	i = 0;
	while (i < playerSize)
	{
		j = 0;
		while (j < playerSize)
		{
			mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX + i, 16711680);
			mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX + i + playerStep, 0);
			j++;
		}
		i++;
	}
}
