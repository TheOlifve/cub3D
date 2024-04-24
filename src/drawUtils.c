/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:19:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 22:12:11 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	rayLen(t_game *game, float x, float y)
{
	float	a;
	float	b;

	a = p->oX - x;
	b = p->oY - y;
	return (sqrt((a * a) + (b * b)));
}

void	shorterRay(t_game *game, float rayA)
{
	float	cosA;

	RAY->c1 = rayLen(game, RAY->hX, RAY->hY);
	RAY->c2 = rayLen(game, RAY->vX, RAY->vY);
	cosA = p->pA - rayA;
	if (cosA < 0)
		cosA += 2 * PI;
	if (cosA > 2 * PI)
		cosA -= 2 * PI;
	if (RAY->c1 < RAY->c2)
	{
		RAY->dist = RAY->c1 * cos(cosA);
		game->wallClr = game->hWallClr;
		// if (RAY->hdX != 1000)
		// {
		// 	RAY->dist = rayLen(game, RAY->hdX, RAY->hdY) * cos(cosA);
		// 	game->wallClr = 150;
		// }
	}
	else if (RAY->c1 > RAY->c2)
	{
		RAY->dist = RAY->c2 * cos(cosA);
		game->wallClr = game->vWallClr;
		// if (RAY->vdX != 1000)
		// {
		// 	RAY->dist = rayLen(game, RAY->vdX, RAY->vdY) * cos(cosA);
		// 	game->wallClr = 150;
		// }
	}
}

void	resetCoords(t_game *game)
{
	RAY->hX = 1000;
	RAY->hY = 1000;
	RAY->vX = 1000;
	RAY->vY = 1000;
	RAY->hdX = 1000;
	RAY->hdY = 1000;
	RAY->vdX = 1000;
	RAY->vdY = 1000;
}
