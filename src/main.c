/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/23 11:48:26 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define DR 0.0174533

void	drawRay2(t_game *game, int clr)
{
	float	rX, rY;
	float	tanA;

	if (p->pA > PI && p->pA < (2 * PI))
	{
		tanA = -1 / tan(p->pA);
		rY = (int)(p->oY / pxlSize) * pxlSize;
		while (rY >= p->hY && rY >= 32)
		{
			rX = ((p->oY - rY) * tanA) + p->oX;
			if (rX / 32 > 0 && rX / 32 <= game->mapW)
				drawPixel(game, rX, rY, clr);
			rY -= 1;
		}
	}
}

void	northIntersec(t_game *game, float rX, float rY, float rA)
{
	float	tmpX;
	float	tanA;

	tanA = -1 / tan(rA);
	rY = ((int)(p->oY / pxlSize) * pxlSize);
	rX = ((p->oY - rY) * tanA) + p->oX;
	printf("rX - %f | rY - %f\np->oX - %f | p->oY - %f\n", rX, rY,p->oX, p->oY);
	printf("%f\n",rA);
	tmpX = pxlSize * tanA;
	while (rY >= 0)
	{
		if ((int)rX >= 0 && ((int)rX / pxlSize) < game->mapW)
		{
			if (game->map[(int)rY / pxlSize] && rY < p->oY &&
				(game->map[((int)rY - (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == '1' ||
					game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
			{
				p->hX = rX;
				p->hY = rY;
				break ;
			}
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
	// printf("rX - %f | rY - %f\np->oX - %f | p->oY - %f\n", rX, rY,p->oX, p->oY);
	// printf("%f\n",rA);
	// rX *= -1;
	tmpX = -pxlSize * tanA;
	while (rY <= game->mapH * pxlSize)
	{
		if ((int)rX >= 0 && ((int)rX / pxlSize) < game->mapW)
		{
			if (game->map[(int)rY / pxlSize] && rY > p->oY &&
				(game->map[((int)rY + (pxlSize - 1)) / pxlSize][(int)rX / pxlSize] == '1' ||
					game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
			{
				p->hX = rX;
				p->hY = rY;
				break ;
			}
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
			if (game->map[(int)rY / pxlSize] && rX < p->oX &&
				(game->map[(int)rY / pxlSize][((int)rX - (pxlSize - 1)) / pxlSize] == '1' ||
					game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
			{
				p->vX = rX;
				p->vY = rY;
				break ;
			}
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
			if (game->map[(int)rY / pxlSize] && rX > p->oX &&
				(game->map[(int)rY / pxlSize][((int)rX + (pxlSize - 1)) / pxlSize] == '1' ||
					game->map[(int)rY / pxlSize][(int)rX / pxlSize] == '1'))
			{
				p->vX = rX;
				p->vY = rY;
				break ;
			}
			else
				rY += tmpY;
		}
		rX += pxlSize;
	}
}

void	drawRay(t_game *game)
{
	float	rA;
	float	cosA;

	rA = p->pA - (DR * 25);
	if (rA < 0)
		rA += 2 * PI;
	for(int r = 0; r < 50; r++)
	{
		p->hX = 1000;
		p->hY = 1000;
		p->vX = 1000;
		p->vY = 1000;
		if (rA > 2 * PI)
			rA = 0;
		if (rA > PI)
			northIntersec(game, 0, 0, rA);
		else if (rA < PI)
			southIntersec(game, 0, 0, rA);
		if (rA > PI2 && rA < PI3)
			westIntersec(game, 0, 0, rA);
		else if (rA > PI3 || rA < PI2)
			eastIntersec(game, 0, 0, rA);
		RAY->a1 = p->oX - p->hX;
		RAY->b1 = p->oY - p->hY;
		RAY->c1 = sqrt((RAY->a1 * RAY->a1) + (RAY->b1 * RAY->b1));
		RAY->a2 = p->oX - p->vX;
		RAY->b2 = p->oY - p->vY;
		RAY->c2 = sqrt((RAY->a2 * RAY->a2) + (RAY->b2 * RAY->b2));
		// printf("hX - %f | hY - %f\n", p->hX, p->hY);
		// printf("vX - %f | vY - %f\n", p->vX, p->vY);
		// printf("____________________\n");
		cosA = p->pA - rA;
		if (cosA < 0)
			cosA += 2 * PI;
		if (cosA > 2 * PI)
			cosA -= 2 * PI;
		if (RAY->c1 < RAY->c2)
		{
			printf("hX - %f | hY - %f\n", p->hX, p->hY);
			printf("vX - %f | vY - %f\n", p->vX, p->vY);
			printf("____________________\n");
		}
		RAY->x = p->hX;
		RAY->y = p->hY;
		RAY->dist = RAY->c1 * cos(cosA);
		game->wall_clr = 16711680;
		if (RAY->c1 > RAY->c2)
		{
			RAY->dist = RAY->c2 * cos(cosA);
			RAY->x = p->vX;
			RAY->y = p->vY;
			game->wall_clr = 8914952;
		}
		// drawPixel(game, RAY->x, RAY->y, 65280);
		float wallH = (MLX->h * pxlSize) / RAY->dist;
		// printf("%f\n",wallH);
		if (wallH > MLX->h)
			wallH = MLX->h;
		drawWall(game, r, wallH);
		if (rA > 2 * PI)
			rA = 0;
		rA += DR;
	}
}

int	keyPress(int key, t_game *game)
{
	// drawPlayer(game, 0);
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
	else if (key == 123)
		rotateLeft(game);
	else if (key == 124)
		rotateRight(game);
	drawCeilingAndFloor(game);
	// drawMiniMap(game);
	// drawPlayer(game, 16711680);
	drawRay(game);
	mlx_put_image_to_window(MLX->pMlx, MLX->win, IMG->pImg, 0, 0);
	return (0);
}

t_player *newPlayer(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player) * 1);
	player->oX = 0;
	player->oY = 0;
	player->x1 = 0;
	player->y1 = 0;
	player->x2 = 0;
	player->y2 = 0;
	player->x3 = 0;
	player->y3 = 0;
	player->x4 = 0;
	player->y4 = 0;
	player->dX = 0.0;
	player->dY = 0.0;
	player->pA = 0.0;
	player->vX = 1000;
	player->vY = 1000;
	player->hX = 1000;
	player->hY = 1000;
	return (player);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		err_exit(0);
	game = malloc(sizeof(t_game));
	MLX = malloc(sizeof(t_mlx));
	IMG = malloc(sizeof(t_img));
	RAY = malloc(sizeof(t_ray));
	MLX->w = 800;
	MLX->h = 800;
	game->pl = newPlayer();
	if (parser(MLX, game, argv[1]))
		err_exit(-1);
	playerInit(game);
	MLX->pMlx = mlx_init();
	MLX->win = mlx_new_window(MLX->pMlx, MLX->w, MLX->h, "cub3D");
	IMG->pImg = mlx_new_image(MLX->pMlx, MLX->w, MLX->h);
	IMG->aImg = mlx_get_data_addr(IMG->pImg, &IMG->bpp, &IMG->line_len, &IMG->endian);
	drawCeilingAndFloor(game);
	// drawMiniMap(game);
	// drawPlayer(game, 16711680);
	mlx_put_image_to_window(MLX->pMlx, MLX->win, IMG->pImg, 0, 0);
	mlx_hook(MLX->win, 2, 1L << 0, keyPress, game);
	mlx_hook(MLX->win, 17, 1L << 0, my_exit, MLX);
	mlx_loop(MLX->pMlx);
	return (0);
}