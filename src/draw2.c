/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:59:11 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/23 13:09:29 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
				drawBlock(game, x, y, 16777215);
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
