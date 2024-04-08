/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:23:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 11:22:27 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	drawPixel(t_mlx *mlx, int x, int y, int clr)
{
	int	i;
	int	j;

	x *= pxlSize;
	y *= pxlSize;
	i = 0;
	while (i < pxlSize)
	{
		j = 0;
		while (j < pxlSize)
		{
			mlx_pixel_put(mlx, mlx->mlx_win, y + j, x + i, clr);
			j++;
		}
		i++;
	}
}

void	playerIn(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'N')
		game->pl->pA = PI;
	else if(game->map[x][y] == 'S')
		game->pl->pA = 0;
	else if(game->map[x][y] == 'W')
		game->pl->pA = PI;
	else
		game->pl->dY = 0;
	game->pl->dX = cos(game->pl->pA);
	game->pl->dY = sin(game->pl->pA);
	game->pl->oX = (x * pxlSize) + (playerSize / 2);
	game->pl->oY = (y * pxlSize) + (playerSize / 2);
	game->pl->lX = x * pxlSize;
	game->pl->lY = y * pxlSize;
}

void	drawMap(t_mlx *mlx, t_game	*game)
{
	int	x;
	int	y;
	
	x = 0;
	while (game->map && game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				drawPixel(mlx, x, y, 16777215);
			else if (game->map[x][y] == 'N' || game->map[x][y] == 'S'
						|| game->map[x][y] == 'W' || game->map[x][y] == 'E')
				playerIn(game, x, y);
			y++;
		}
		x++;
	}
}

void	drawPlayer(t_mlx *mlx, t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < playerSize)
	{
		j = 0;
		while (j < playerSize)
		{
			mlx_pixel_put(mlx, mlx->mlx_win, game->pl->lY + j, game->pl->lX + i, 16711680);
			j++;
		}
		i++;
	}
}