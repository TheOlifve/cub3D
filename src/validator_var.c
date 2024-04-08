/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:36:55 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/05 14:49:21 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_int(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	valid_color(char *str, int i, int j)
{
	char	**clr;

	clr = ft_split(str, ',');
	if (!clr)
		return (1);
	if (clr[0] != NULL && clr[1] != NULL && clr[2] != NULL)
	{
		while (++i < 3)
		{
			if (valid_int(clr[i]))
			{
				doublefree(clr);
				return (1);
			}
			j = ft_atoi(clr[i]);
			if (j < 0 || j > 255)
			{
				doublefree(clr);
				return (1);
			}
		}
	}
	doublefree(clr);
	return (0);
}
