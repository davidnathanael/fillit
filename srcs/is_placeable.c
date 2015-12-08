/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:50:50 by adompe            #+#    #+#             */
/*   Updated: 2015/12/08 21:53:19 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_placeable.h"
#include "tab2list.h"
#include "libft.h"

int	ft_is_placeable(char **grid, t_tetr *tetri, int x, int y)
{
	int		i;
	int		len;
	t_pos	*pos;

	len = ft_strlen(grid[0]);
	pos = tetri->pos;
	i = 0;
	while (i < 4)
	{
		if (x + pos[i].x < 0 || x + pos[i].x > len &&
				y + pos[i].y < 0 && y + pos[i].y > len)
			if (grid[x + pos[i].x][y + pos[i].y] == '#')
							return (0);
		i++;
	}
	ft_place_tetri(grid, tetri, x, y);
	return (1);
}

void	ft_place_tetri(char **grid, t_tetr *tetr, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[y + tetr->pos[i].y][x + tetr->pos[i].x] = tetr->letter;
	}
}
