/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:00:19 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/21 01:00:39 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initCoords(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'N')
		p->pA = PI3;
	else if(game->map[y][x] == 'S')
		p->pA = PI2;
	else if(game->map[y][x] == 'W')
		p->pA = PI;
	else
		p->pA = 0;
	p->x1 = x * pxlSize;
	p->y1 = y * pxlSize;
	p->x2 = p->x1 + playerSize;
	p->y2 = p->y1;
	p->x3 = p->x2;
	p->y3 = p->y2 + playerSize;
	p->x4 = p->x3 - playerSize;
	p->y4 = p->y3;
	p->oX = p->x1 + (playerSize / 2);
	p->oY = p->y1 + (playerSize / 2);
	p->dX = cos(p->pA) * playerStep;
	p->dY = sin(p->pA) * playerStep;
}

void	playerInit(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
					initCoords(game, x, y);
					return ;
			}
			x++;
		}
		y++;
	}
}
