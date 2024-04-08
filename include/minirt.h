/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:20:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/08 11:18:00 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define pxlSize 32
# define playerSize 16
# define playerStep 8
# define PI 3.14159265359

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_mlx
{
	int		x;
	int		y;
	int		h;
	int		w;
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_player
{
	int		oX;
	int		oY;
	int		lX;
	int		lY;
	float	dX;
	float	dY;
	float	pA;
}			t_player;

typedef struct s_game
{
	int			floor_clr;
	int			ceiling_clr;
	char		**tmp;
	char		**map;
	char		**params;
	void		*NO;
	void		*SO;
	void		*WE;
	void		*EA;
	t_mlx		*mlx;
	t_player	*pl;
}			t_game;

//	PARSER
int		parser(t_mlx *mlx, t_game *game, char *file);
int		valid_file_type(char *s1, char *s2);

//	UTILS
int		rgbtoi(char	*color);
int		err_print(int num);
int		my_exit(t_mlx *mlx);
char	*get_next_line(int fd);
char	**read_file(int fd, char *file);
void	err_exit(int num);
void	doublefree(char **str);
float	my_atof(char *str);

//	TEXTURES
int	textures_init(t_mlx *mlx, t_game *game);
int	valid_texture(char *tex_path);
int	ea_texture(t_mlx *mlx, t_game *game);
int	so_texture(t_mlx *mlx, t_game *game);
int	we_texture(t_mlx *mlx, t_game *game);
int	ea_texture(t_mlx *mlx, t_game *game);

//	Draw
void	drawMap(t_mlx *mlx, t_game	*game);
void	drawPlayer(t_mlx *mlx, t_game *game);
void	drawPixel(t_mlx *mlx, int x, int y, int clr);

//	Move
void	moveUp(t_game *game, t_mlx *mlx);
void	moveDown(t_game *game, t_mlx *mlx);
void	moveLeft(t_game *game, t_mlx *mlx);
void	moveMouse(t_game *game, t_mlx *mlx);
void	moveRight(t_game *game, t_mlx *mlx);

#endif