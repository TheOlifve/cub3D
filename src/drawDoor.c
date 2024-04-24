/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawDoor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:44:30 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 21:05:44 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define hY1 (int)RAY->hY / pxlSize
#define hX1 (int)RAY->hX / pxlSize
#define vY1 (int)RAY->vY / pxlSize
#define vX1 (int)RAY->vX / pxlSize

void	openDoor(t_game *game)
{
	if (RAY->c1 < RAY->c2)
	{
		if (game->map[hY1][hX1] == 'D')
			game->map[hY1][hX1] = 'd';
		else if (game->map[hY1][hX1] == 'd')
			game->map[hY1][hX1] = 'D';
	}
	else if (RAY->c1 > RAY->c2)
	{
		if (game->map[vY1][vX1] == 'D')
			game->map[vY1][vX1] = 'd';
		else if (game->map[vY1][vX1] == 'd')
			game->map[vY1][vX1] = 'D';
	}
}

// void	drawDoor(t_game *game, float rayA)
// {
// 	rayA = p->pA - (DR * 25);
// 	if (rayA < 0)
// 		rayA += 2 * PI;
// 	for(int r = 0; r < 50; r++)
// 	{
// 		resetCoords(game);
// 		if (rayA > 2 * PI)
// 			rayA = 0;
// 		if (rayA > PI)
// 			doorNorthIntersec(game, 0, 0, rayA);
// 		else if (rayA < PI)
// 			doorSouthIntersec(game, 0, 0, rayA);
// 		if (rayA > PI2 && rayA < PI3)
// 			doorWestIntersec(game, 0, 0, rayA);
// 		else if (rayA > PI3 || rayA < PI2)
// 			doorEastIntersec(game, 0, 0, rayA);
// 		shorterRay(game, rayA);
// 		if (RAY->vX == 1000 && RAY->hX != 1000)
// 		{
// 			if (game->map[hY1][hX1] == 'D')
// 				game->wallClr = 150;
// 			else
// 				continue;
// 			drawWall(game, r);
// 		}
// 		else if (RAY->vX != 1000 && RAY->hX == 1000)
// 		{
// 			if (game->map[vY1][vX1] == 'D' &&
// 					game->map[vY1 + 1][vX1] == '1' &&
// 						game->map[vY1 - 1][vX1] == '1')
// 				game->wallClr = 150;
// 			else
// 				continue;
// 			drawWall(game, r);
// 		}
		
// 	// else if (game->map[vY][vX] == 'd' &&
// 	// 			game->map[vY + 1][vX] == '1' &&
// 	// 				game->map[vY - 1][vX] == '1')
// 	// 		game->wallClr = 255;
// 		rayA += DR;
// 	}
// 			// else if (game->map[hY1][hX1] == 'd' &&
// 			// 		game->map[hY1 - 1][hX1] == '1' &&
// 			// 			game->map[hY1 + 1][hX1] == '1')
// 	}