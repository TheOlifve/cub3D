/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 11:13:22 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	keyPress(int key, t_game *game)
{
	if (key == 53)
		my_exit(game->mlx);
	else if (key == 13)
		moveUp(game, game->mlx);
	else if (key == 0)
		moveLeft(game, game->mlx);
	else if (key == 1)
		moveDown(game, game->mlx);
	else if (key == 2)
		moveRight(game, game->mlx);
	else if (key == 123)
		;
	else if (key == 124)
		;
	return (0);
}

t_player *newPlayer(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player) * 1);
	player->oX = 0;
	player->oY = 0;
	player->lX = 0;
	player->lY = 0;
	player->dX = 0.0;
	player->dY = 0.0;
	player->pA = 0.0;
	return (player);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		err_exit(0);
	game = malloc(sizeof(t_game));
	game->mlx = malloc(sizeof(t_mlx));
	game->mlx->w = 800;
	game->mlx->h = 800;
	game->pl = newPlayer();
	if (parser(game->mlx, game, argv[1]))
		err_exit(-1);
	game->mlx->mlx = mlx_init();
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx, game->mlx->w, game->mlx->h, "cub3D");
	drawMap(game->mlx, game);
	drawPlayer(game->mlx, game);
	mlx_hook(game->mlx->mlx_win, 2, 1L << 0, keyPress, game);
	mlx_hook(game->mlx->mlx_win, 17, 1L << 0, my_exit, game->mlx);
	mlx_loop(game->mlx->mlx);
	return (0);
}