/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:23:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/15 16:12:54 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "place_tetri.h"
#include "grid.h"
#include "tab2list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_isplaced(char **grid, t_tetr *tetri, int x, int y)
{
	int		i;
	int		j;
	int		width;
	int		placed;

	i = y;
	j = x;
	width = ft_strlen(grid[0]);
	placed = -1;
	while (i < width && tetri)
	{
		if ((placed = ft_is_placeable(grid, tetri, j, i)))
		{
			tetri->pos_in_grid.x = j;
			tetri->pos_in_grid.y = i;
			return (placed);
		}
		j = (tetri->width == (width - j - 1)) ? width : j + 1;
		if (j >= width)
		{
			j = 0;
			i = (tetri->height == (width - i - 1)) ? width : i + 1;
		}
	}
	return (placed);
}

int		ft_is_placeable(char **grid, t_tetr *tetri, int x, int y)
{
	int		i;
	int		len;
	t_pos	*pos;

	len = ft_strlen(grid[0]) - 1;
	pos = tetri->pos;
	i = 0;
	while (i < 4)
	{
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

void	ft_set_tetri_size(t_tetr *tetr, int count)
{
	int	x[2];
	int	y[2];

	x[0] = 0;
	x[1] = 0;
	y[0] = 0;
	y[1] = 0;
	while (count--)
	{
		if (tetr->pos[count].x <= x[0])
			x[0] = tetr->pos[count].x;
		if (tetr->pos[count].y <= y[0])
			y[0] = tetr->pos[count].y;
	}
	count = 4;
	while (count--)
	{
		if (tetr->pos[count].x >= x[1])
			x[1] = tetr->pos[count].x;
		if (tetr->pos[count].y <= y[1])
			y[1] = tetr->pos[count].y;
	}
	tetr->width = x[1] - x[0];
	tetr->height = y[1] - y[0];
}
