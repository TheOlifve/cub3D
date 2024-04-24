/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectionUtils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:47:20 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 22:12:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	northWall(t_game *game, float rX, float rY)
{
	// if (game->map[(int)rY / pxlSize] && rY < p->oY &&
	// 	(game->map[((int)rY - (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == 'D' ||
	// 			game->map[(int)rY / pxlSize][(int)rX / pxlSize] == 'D'))
	// {
	// 	RAY->hdX = rX;
	// 	RAY->hdY = rY;
	// }
	if (game->map[(int)rY / pxlSize] && rY < p->oY &&
		(game->map[((int)rY - (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == '1' ||
				game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
	{
		game->hWallClr = 16711680;
		RAY->hX = rX;
		RAY->hY = rY;
	}
	else
		return (0);
	return (1);
}

int	southWall(t_game *game, float rX, float rY)
{
	// if (game->map[(int)rY / pxlSize] && rY > p->oY &&
	// 	(game->map[((int)rY + (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == 'D' ||
	// 		game->map[(int)rY / pxlSize][(int)rX / pxlSize] == 'D'))
	// {
	// 	RAY->hdX = rX;
	// 	RAY->hdY = rY;
	// }
	if (game->map[(int)rY / pxlSize] && rY > p->oY &&
		(game->map[((int)rY + (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == '1' ||
			game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
	{
		game->hWallClr = 8914952;
		RAY->hX = rX;
		RAY->hY = rY;
	}
	else
		return (0);
	return (1);
}

int	westWall(t_game *game, float rX, float rY)
{
	// if (game->map[(int)rY / pxlSize] && rX < p->oX &&
	// 	(game->map[(int)rY / pxlSize][((int)rX - (pxlSize - 1)) / pxlSize] == 'D' ||
	// 		game->map[(int)rY / pxlSize][(int)rX / pxlSize] == 'D'))
	// {
	// 	RAY->vdX = rX;
	// 	RAY->vdY = rY;
	// }
	if (game->map[(int)rY / pxlSize] && rX < p->oX &&
		(game->map[(int)rY / pxlSize][((int)rX - (pxlSize - 1)) / pxlSize] == '1' ||
			game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
	{
		game->vWallClr = 150;
		RAY->vX = rX;
		RAY->vY = rY;
	}
	else
		return (0);
	return (1);
}

int	eastWall(t_game *game, float rX, float rY)
{
	// if (game->map[(int)rY / pxlSize] && rX > p->oX &&
	// 	(game->map[(int)rY / pxlSize][((int)rX + (pxlSize - 1)) / pxlSize] == 'D' ||
	// 		game->map[(int)rY / pxlSize][(int)rX / pxlSize] == 'D'))
	// {
	// 	RAY->vdX = rX;
	// 	RAY->vdY = rY;
	// }
	if (game->map[(int)rY / pxlSize] && rX > p->oX &&
		(game->map[(int)rY / pxlSize][((int)rX + (pxlSize - 1)) / pxlSize] == '1' ||
			game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
	{
		game->vWallClr = 255;
		RAY->vX = rX;
		RAY->vY = rY;
	}
	else
		return (0);
	return (1);
}
