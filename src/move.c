/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveForward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:26:25 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 20:48:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	moveForward(t_game *game)
{
	p->dX = cos(p->pA) * playerStep;
	p->dY = sin(p->pA) * playerStep;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}

void	moveBackward(t_game *game)
{
	p->dX = cos(p->pA) * playerStep;
	p->dY = sin(p->pA) * playerStep;
	moveCoordsBack(game);
	if (checkWall(game))
		;
	else
		return moveCoords(game);
}

void	moveLeft(t_game *game)
{
	p->dX = cos(p->pA - PI2) * playerStep;
	p->dY = sin(p->pA - PI2) * playerStep;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}

void	moveRight(t_game *game)
{
	p->dX = cos(p->pA + PI2) * playerStep;
	p->dY = sin(p->pA + PI2) * playerStep;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}
