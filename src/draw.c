/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:23:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/21 01:02:36 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	drawPixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = IMG->aImg + (y * IMG->line_len + x * (IMG->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	drawBlock(t_game *game, int x, int y, int clr)
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
			drawPixel(game, x + i, y + j, clr);
			j++;
		}
		i++;
	}
}

void	drawMiniMap(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				drawBlock(game, x, y, 0);
			x++;
		}
		y++;
	}
}

void	drawPlayer(t_game *game, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < playerSize)
	{
		j = 0;
		while (j < playerSize)
		{
			drawPixel(game, p->x1 + i, p->y1 + j, color);
			j++;
		}
		i++;
	}
}

void	drawCeilingAndFloor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MLX->h / 2)
	{
		x = 0;
		while (x < MLX->w)
		{
			drawPixel(game, x, y, ceilingCLR);
			x++;
		}
		y++;
	}
	while (y < MLX->h)
	{
		x = 0;
		while (x < MLX->w)
		{
			drawPixel(game, x, y, floorCLR);
			x++;
		}
		y++;
	}
}
