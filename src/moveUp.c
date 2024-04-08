/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveUp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:26:25 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 15:41:22 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	moveUp(t_game *game, t_mlx *mlx)
{
	int	i;
	int	j;

	// if (checkUp(game))
	// else
	// 	return ;
	printf("%f | %f\n",game->pl->dX,game->pl->dY);
	// printf("lX - %f | lY - %f\noX - %f | oY - %f\n",game->pl->lX, game->pl->lY, game->pl->oX, game->pl->oY);
	game->pl->lX = game->pl->lX + (cos(game->pl->pA) * playerStep);
	game->pl->lY = game->pl->lY + (sin(game->pl->pA) * playerStep);
	game->pl->oX = game->pl->oX + (cos(game->pl->pA) * playerStep);
	game->pl->oY = game->pl->oY + (sin(game->pl->pA) * playerStep);
	// printf("lX - %f | lY - %f\noX - %f | oY - %f\n",game->pl->lX, game->pl->lY, game->pl->oX, game->pl->oY);
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
