/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:43:33 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 14:23:43 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	moveCoords(t_game *game)
{
	p->x1 = p->x1 + p->dX;
	p->y1 = p->y1 + p->dY;
	p->x2 = p->x2 + p->dX;
	p->y2 = p->y2 + p->dY;
	p->x3 = p->x3 + p->dX;
	p->y3 = p->y3 + p->dY;
	p->x4 = p->x4 + p->dX;
	p->y4 = p->y4 + p->dY;
	p->oX = p->oX + p->dX;
	p->oY = p->oY + p->dY;
}

void	moveCoordsBack(t_game *game)
{
	p->x1 = p->x1 - p->dX;
	p->y1 = p->y1 - p->dY;
	p->x2 = p->x2 - p->dX;
	p->y2 = p->y2 - p->dY;
	p->x3 = p->x3 - p->dX;
	p->y3 = p->y3 - p->dY;
	p->x4 = p->x4 - p->dX;
	p->y4 = p->y4 - p->dY;
	p->oX = p->oX - p->dX;
	p->oY = p->oY - p->dY;
}

int	checkWall(t_game *game)
{
	int	x;
	int	y;
	
	x = p->x1 / pxlSize;
	y = p->y1 / pxlSize;
	if (game->map[y][x] == '1' || game->map[y][x] == 'D')
		return (0);
	x = p->x2 / pxlSize;
	y = p->y2 / pxlSize;
	if (game->map[y][x] == '1' || game->map[y][x] == 'D')
		return (0);
	x = p->x3 / pxlSize;
	y = p->y3 / pxlSize;
	if (game->map[y][x] == '1' || game->map[y][x] == 'D')
		return (0);
	x = p->x4 / pxlSize;
	y = p->y4 / pxlSize;
	if (game->map[y][x] == '1' || game->map[y][x] == 'D')
		return (0);
	return (1);
}
