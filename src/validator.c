/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:03:17 by hrahovha          #+#    #+#             */
/*   Updated: 2024/04/05 16:06:26 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_file_type(char *s1, char *s2)
{
	int		i;
	int		j;

	if (!s1 || !s2)
		return (1);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (i <= j)
		return (1);
	while (j >= 0)
	{
		if (s1[i] != s2[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}
