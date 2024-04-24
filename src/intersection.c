/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:47:20 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 21:46:49 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	northIntersec(t_game *game, float rX, float rY, float rA)
{
	float	tmpX;
	float	tanA;

	tanA = -1 / tan(rA);
	rY = ((int)(p->oY / pxlSize) * pxlSize);
	rX = ((p->oY - rY) * tanA) + p->oX;
	tmpX = pxlSize * tanA;
	while (rY >= 0)
	{
		if ((int)rX >= 0 && ((int)rX / pxlSize) < game->mapW)
		{
			if (northWall(game, rX, rY))
				break;
			else
				rX += tmpX;
		}
		rY -= pxlSize;
	}
}


void	southIntersec(t_game *game, float rX, float rY, float rA)
{
	float	tmpX;
	float	tanA;

	tanA = -1 / tan(rA);
	rY = ((int)(p->oY / pxlSize) * pxlSize) + pxlSize;
	rX = ((p->oY - rY) * tanA) + p->oX;
	tmpX = -pxlSize * tanA;
	while (rY <= game->mapH * pxlSize)
	{
		if ((int)rX >= 0 && ((int)rX / pxlSize) < game->mapW)
		{
			if (southWall(game, rX, rY))
				break;
			else
				rX += tmpX;
		}
		rY += pxlSize;
	}
}

void	westIntersec(t_game *game, float rX, float rY, float rA)
{
	float	tmpY;
	float	tanA;

	tanA = tan(rA);
	rX = ((int)(p->oX / pxlSize) * pxlSize);
	rY = ((rX - p->oX) * tanA) + p->oY;
	tmpY = -pxlSize * tanA;
	while (rX >= 0)
	{
		if ((int)rY >= 0 && ((int)rY / pxlSize) < game->mapH)
		{
			if (westWall(game, rX, rY))
				break;
			else
				rY += tmpY;
		}
		rX -= pxlSize;
	}
}

void	eastIntersec(t_game *game, float rX, float rY, float rA)
{
	float	tmpY;
	float	tanA;

	tanA = tan(rA);
	rX = ((int)(p->oX / pxlSize) * pxlSize) + pxlSize;
	rY = ((rX - p->oX) * tanA) + p->oY;
	tmpY = pxlSize * tanA;
	while (rX <= game->mapW * pxlSize)
	{
		if ((int)rY >= 0 && ((int)rY / pxlSize) < game->mapH)
		{
			if (eastWall(game, rX, rY))
				break;
			else
				rY += tmpY;
		}
		rX += pxlSize;
	}
}
