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
	p->dX = cos(p->pA) * playerSpeed;
	p->dY = sin(p->pA) * playerSpeed;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}

void	moveBackward(t_game *game)
{
	p->dX = cos(p->pA) * playerSpeed;
	p->dY = sin(p->pA) * playerSpeed;
	moveCoordsBack(game);
	if (checkWall(game))
		;
	else
		return moveCoords(game);
}

void	moveLeft(t_game *game)
{
	p->dX = cos(p->pA - PI2) * playerSpeed;
	p->dY = sin(p->pA - PI2) * playerSpeed;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}

void	moveRight(t_game *game)
{
	p->dX = cos(p->pA + PI2) * playerSpeed;
	p->dY = sin(p->pA + PI2) * playerSpeed;
	moveCoords(game);
	if (checkWall(game))
		;
	else
		return moveCoordsBack(game);
}

int	keyPress(int key, t_game *game)
{
	if (key == 53)
		my_exit(game->mlx);
	else if (key == 13)
		moveForward(game);
	else if (key == 0)
		moveLeft(game);
	else if (key == 1)
		moveBackward(game);
	else if (key == 2)
		moveRight(game);
	else if (key == 14)
		openDoor(game);
	drawScene(game, 0);
	return (0);
}
