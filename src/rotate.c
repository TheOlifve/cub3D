/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:24:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/23 17:25:10 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define ANG 0.06981317008

void	rotateRight(t_game *game)
{
	p->pA += ANG;
	if (p->pA > (PI * 2))
		p->pA = 0;
	p->dX = cos(p->pA) * playerSpeed;
	p->dY = sin(p->pA) * playerSpeed;
}

void	rotateLeft(t_game *game)
{
	p->pA -= ANG;
	if (p->pA < 0)
		p->pA = 2 * PI;
	p->dX = cos(p->pA) * playerSpeed;
	p->dY = sin(p->pA) * playerSpeed;
}
