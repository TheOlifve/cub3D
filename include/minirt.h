/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:20:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/22 23:59:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define pxlSize 16
# define playerSize 4
# define playerStep 4
# define PI 3.141592654
# define PI2 PI / 2
# define PI3 3 * (PI / 2)
# define floorCLR 0
# define ceilingCLR 16777215
# define p game->pl // player
# define IMG game->mlx->img // img3d
# define MLX game->mlx // mlx
# define RAY game->ray // ray

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_ray
{
	float	x;
	float	y;
	float	a1;
	float	a2;
	float	b1;
	float	b2;
	float	c1;
	float	c2;
	float	dist;
}		t_ray;


typedef struct s_img
{
	int			x;
	int			y;
	int			bpp;
	int			line_len;
	int			endian;
	void		*pImg;
	char		*aImg;
}			t_img;


typedef struct s_mlx
{
	int		x;
	int		y;
	int		h;
	int		w;
	void	*pMlx;
	void	*pMlx2;
	void	*win;
	void	*win2;
	t_img	*img;
}			t_mlx;

typedef struct s_player
{
	float	oX;
	float	oY;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	x3;
	float	y3;
	float	x4;
	float	y4;
	float	dX;
	float	dY;
	float	pA;
	float	hX;
	float	hY;
	float	vX;
	float	vY;
}			t_player;

typedef struct s_game
{
	int			wall_clr;
	int			floor_clr;
	int			ceiling_clr;
	int			mapH;
	int			mapW;
	char		**tmp;
	char		**map;
	char		**params;
	void		*NO;
	void		*SO;
	void		*WE;
	void		*EA;
	t_mlx		*mlx;
	t_ray		*ray;
	t_player	*pl;
}			t_game;

//	PARSER
int		parser(t_mlx *mlx, t_game *game, char *file);
int		valid_file_type(char *s1, char *s2);
void	mapSize(t_game *game);
void	playerInit(t_game *game);

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
void	drawMiniMap(t_game	*game);
void	drawCeilingAndFloor(t_game *game);
void	drawPlayer(t_game *game, int color);
void	drawWall(t_game *game, int r, int h);
void	drawBlock(t_game *game, int x, int y, int clr);
void	drawPixel(t_game *game, int x, int y, int color);

//	Move
int		checkWall(t_game *game);
void	moveLeft(t_game *game);
void	moveRight(t_game *game);
void	moveForward(t_game *game);
void	moveBackward(t_game *game);
void	moveCoords(t_game *game);
void	moveCoordsBack(t_game *game);
void	moveMouse(t_game *game, t_mlx *mlx);


//	Rotate
void	rotateLeft(t_game *game);
void	rotateRight(t_game *game);

#endif