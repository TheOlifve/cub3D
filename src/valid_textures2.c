/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:06:53 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/06 15:29:12 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_texture(char *tex_path)
{
	int	fd;

	if (valid_file_type(tex_path, ".xpm"))
		return (1);
	fd = open(tex_path, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}
