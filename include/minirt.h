/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:20:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/24 23:49:04 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define pxlSize 16
# define playerSize 4
# define playerSpeed 4
# define mouseSens 20
# define DR 0.0174533
# define PI 3.141592654
# define PI2 PI / 2
# define PI3 3 * (PI / 2)
# define floorCLR 0
# define ceilingCLR 16777215
# define p game->player // player
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
	float	hX;//X of ray intersection with horizontal walls
	float	hY;//Y of ray intersection with horizontal walls
	float	vX;//X of ray intersection with vertical walls
	float	vY;//Y of ray intersection with vertical walls
	float	hdX;//X of ray intersection with horizontal doors
	float	hdY;
	float	vdX;//X of ray intersection with vertical doors
	float	vdY;
	float	c1;
	float	c2;
	float	dist;//Distance between player and wall (Ray lenght)
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
	int		winH;
	int		winW;
	void	*pMlx;
	void	*win;
	t_img	*img;
}			t_mlx;

typedef struct s_player
{
	float	oX;// Center
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
}			t_player;

typedef struct s_game
{
	int			wallClr;
	int			floorClr;
	int			hWallClr;
	int			vWallClr;
	int			ceilingClr;
	int			mapH;
	int			mapW;
	char		**tmp;
	char		**map;
	char		**params;
	void		*imgNO;
	void		*imgSO;
	void		*imgWE;
	void		*imgEA;
	t_mlx		*mlx;
	t_ray		*ray;
	t_player	*player;
}			t_game;

//	PARSER
int		parser(t_game *game, char *file);
int		valid_file_type(char *s1, char *s2);
void	mapSize(t_game *game);

//	INIT
void	initGame(t_game *game);

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
int	valid_texture(char *tex_path);
int	ea_texture(t_mlx *mlx, t_game *game);
int	so_texture(t_mlx *mlx, t_game *game);
int	we_texture(t_mlx *mlx, t_game *game);
int	ea_texture(t_mlx *mlx, t_game *game);
int	textures_init(t_mlx *mlx, t_game *game);

//	DRAW
void	drawDoor(t_game *game, float rayA);
void	resetCoords(t_game *game);
void	drawMiniMap(t_game	*game);
void	drawWall(t_game *game, int pos);
void	drawCeilingAndFloor(t_game *game);
void	drawScene(t_game *game, float rayA);
void	drawPlayer(t_game *game, int color);
void	drawBlock(t_game *game, int x, int y, int clr);
void	drawPixel(t_game *game, int x, int y, int color);

//	MOVE
int		checkWall(t_game *game);
int		moveMouse(t_game *game);
int		keyPress(int key, t_game *game);
void	openDoor(t_game *game);
void	moveCoords(t_game *game);
void	moveCoordsBack(t_game *game);


//	ROTATE
void	rotateLeft(t_game *game);
void	rotateRight(t_game *game);

//	INTERSECTION
int		eastWall(t_game *game, float rX, float rY);
int		westWall(t_game *game, float rX, float rY);
int		northWall(t_game *game, float rX, float rY);
int		southWall(t_game *game, float rX, float rY);
void	shorterRay(t_game *game, float rayA);
void	eastIntersec(t_game *game, float rX, float rY, float rA);
void	westIntersec(t_game *game, float rX, float rY, float rA);
void	southIntersec(t_game *game, float rX, float rY, float rA);
void	northIntersec(t_game *game, float rX, float rY, float rA);

#endif