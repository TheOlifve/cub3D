/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawScene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:23:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 23:50:12 by hrahovha         ###   ########.fr       */
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

void	drawCeilingAndFloor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MLX->winH / 2)
	{
		x = 0;
		while (x < MLX->winW)
		{
			drawPixel(game, x, y, ceilingCLR);
			x++;
		}
		y++;
	}
	while (y < MLX->winH)
	{
		x = 0;
		while (x < MLX->winW)
		{
			drawPixel(game, x, y, floorCLR);
			x++;
		}
		y++;
	}
}

void	drawWall(t_game *game, int pos)
{
	int	x;
	int	y;
	float wallH;

	y = 0;
	wallH = (MLX->winH * pxlSize) / RAY->dist;
	if (wallH > MLX->winH)
		wallH = MLX->winH;
	while (y < wallH)
	{
		x = 0;
		while (x < 16)
		{
			drawPixel(game, pos * 16 + x, y + 400 - wallH / 2 , game->wallClr);
			x++;
		}
		y++;
	}
}

void	drawScene(t_game *game, float rayA)
{
	drawCeilingAndFloor(game);
	rayA = p->pA - (DR * 25);
	if (rayA < 0)
		rayA += 2 * PI;
	for(int r = 0; r < 50; r++)
	{
		resetCoords(game);
		if (rayA > 2 * PI)
			rayA = 0;
		if (rayA > PI)
			northIntersec(game, 0, 0, rayA);
		else if (rayA < PI)
			southIntersec(game, 0, 0, rayA);
		if (rayA > PI2 && rayA < PI3)
			westIntersec(game, 0, 0, rayA);
		else if (rayA > PI3 || rayA < PI2)
			eastIntersec(game, 0, 0, rayA);
		shorterRay(game, rayA);
		drawWall(game, r);
		rayA += DR;
	}
	mlx_put_image_to_window(MLX->pMlx, MLX->win, IMG->pImg, 0, 0);
}
