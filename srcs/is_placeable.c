/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:50:50 by adompe            #+#    #+#             */
/*   Updated: 2015/12/08 21:55:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_placeable.h"
#include "tab2list.h"

int	ft_is_placeable(char **grid, t_pos *pos, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (x + pos[i] > 0 && grid[x + pos[i].x][y + ])

	}
	
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
