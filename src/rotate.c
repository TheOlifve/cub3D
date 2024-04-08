/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:24:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 14:32:12 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotateRight(t_game *game)
{
	game->pl->pA -= 0.1;
	mlx_pixel_put(game->mlx, game->mlx->mlx_win,
		game->pl->dY + game->pl->oY, game->pl->dX + game->pl->oX, 0);
	if (game->pl->pA < 0)
		game->pl->pA = 2 * PI;
	game->pl->dX = cos(game->pl->pA) * 15;
	game->pl->dY = sin(game->pl->pA) * 15;
	mlx_pixel_put(game->mlx, game->mlx->mlx_win,
		game->pl->dY + game->pl->oY, game->pl->dX + game->pl->oX, 65280);
}

void	rotateLeft(t_game *game)
{
	game->pl->pA += 0.1;
	mlx_pixel_put(game->mlx, game->mlx->mlx_win,
		game->pl->dY + game->pl->oY, game->pl->dX + game->pl->oX, 0);
	if (game->pl->pA > 2 * PI)
		game->pl->pA = 0;
	game->pl->dX = cos(game->pl->pA) * 15;
	game->pl->dY = sin(game->pl->pA) * 15;
	mlx_pixel_put(game->mlx, game->mlx->mlx_win,
		game->pl->dY + game->pl->oY, game->pl->dX + game->pl->oX, 65280);
}
