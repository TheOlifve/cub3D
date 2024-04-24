/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:00:19 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 21:52:43 by hrahovha         ###   ########.fr       */
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
	p->dX = cos(p->pA) * playerSpeed;
	p->dY = sin(p->pA) * playerSpeed;
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
	return (player);
}

void	rayInit(t_game *game)
{
	RAY->hX = 1000;
	RAY->hY = 1000;
	RAY->vX = 1000;
	RAY->vY = 1000;
	RAY->hdX = 1000;
	RAY->hdY = 1000;
	RAY->vdX = 1000;
	RAY->vdY = 1000;
	RAY->c1 = 1000;
	RAY->c2 = 1000;
	RAY->dist = 1000;
}

int	moveMouse(t_game *game)
{
		int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(MLX->win, &x, &y);
	mlx_mouse_hide();
	if (x >= (MLX->winW / 2) + mouseSens)
	{
		mlx_mouse_move(MLX->win, MLX->winW / 2, MLX->winH / 2);
		rotateRight(game);
		drawScene(game, 0);
	}
	else if (x <= (MLX->winW / 2) - mouseSens)
	{
		mlx_mouse_move(MLX->win, MLX->winW / 2, MLX->winH / 2);
		rotateLeft(game);
		drawScene(game, 0);
	}
	return (0);
}

void	  initGame(t_game *game)
{
	MLX = malloc(sizeof(t_mlx));
	IMG = malloc(sizeof(t_img));
	RAY = malloc(sizeof(t_ray));
	MLX->winW = 800;
	MLX->winH = 800;
	game->player = newPlayer();
	playerInit(game);
	rayInit(game);
	MLX->pMlx = mlx_init();
	MLX->win = mlx_new_window(MLX->pMlx, MLX->winW, MLX->winH, "cub3D");
	mlx_mouse_move(MLX->win, MLX->winW / 2, MLX->winH / 2);
	IMG->pImg = mlx_new_image(MLX->pMlx, MLX->winW, MLX->winH);
	IMG->aImg = mlx_get_data_addr(IMG->pImg, &IMG->bpp, &IMG->line_len, &IMG->endian);
	drawScene(game, 0);
	mlx_hook(MLX->win, 2, 1L << 0, keyPress, game);
	mlx_hook(MLX->win, 17, 1L << 0, my_exit, MLX);
	mlx_loop_hook(MLX->pMlx, &moveMouse, (void *)game);
	mlx_loop(MLX->pMlx);
}
