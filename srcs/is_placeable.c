/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:50:50 by adompe            #+#    #+#             */
/*   Updated: 2015/12/09 13:35:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_placeable.h"
#include "tab2list.h"
#include "libft.h"
#include <stdio.h>

int	ft_is_placeable(char **grid, t_tetr *tetri, int x, int y)
{
	int		i;
	int		len;
	t_pos	*pos;

	len = ft_strlen(grid[0]) - 1;
	pos = tetri->pos;
	i = 0;
	//if (pos[0].x == tetri->pos_in_grid.x && pos[0].y == tetri->pos_in_grid.y)
	//	return (0);
	while (i < 4)
	{
		printf("x + pos[].x : %d | y + pos[].y : %d\n", x + pos[i].x, y + pos[i].y);
		if (x + pos[i].x < 0 || x + pos[i].x > len ||
				y + pos[i].y < 0 || y + pos[i].y > len)
			return (0);
		if (grid[y + pos[i].y][x + pos[i].x] != '.')
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
		i++;
	}
}

void	ft_remove_tetri(char **grid, t_tetr *tetr)
{
	t_pos	*pos;
	t_pos	pos_in_grid;
	int		i;

	pos = tetr->pos;
	pos_in_grid = tetr->pos_in_grid;
	i = 0;
	while (i < 4)
	{
		grid[pos_in_grid.y + pos[i].y][pos_in_grid.x + pos[i].x] = '.';
		i++;
	}
}
