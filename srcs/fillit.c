/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/11 16:25:58 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"
#include "check_file.h"
#include "check_tetri.h"
#include "tab2list.h"
#include "grid.h"
#include "place_tetri.h"
#include "libft.h"

int		ft_fillit(int fd)
{
	char	**tetr;
	char	**grid;
	t_list	*list;

	list = NULL;
	tetr = ft_check_file(fd);
	if (!tetr)
		return (ERROR);
	list = ft_tab2list(tetr);
	free(tetr);
	if (!list)
		return (ERROR);
	if (ft_check_tetri(list->head) == NOT_VALID)
		return (ERROR);
	grid = ft_smallest_grid(list->length);
	if (!grid)
		return (ERROR);
	grid = ft_fill_grid(grid, list);
	ft_print_grid(grid);
	return (NO_ERROR);
}

char	**ft_fill_grid(char **grid, t_list *list)
{
	t_tetr	*tmp;

	tmp = list->head;
	while (1)
	{
		while (tmp)
		{
			if (!ft_isplaced(grid, tmp, tmp->pos_in_grid.x, tmp->pos_in_grid.y))
			{
				if (!ft_is_first_placeable(tmp))
					break ;
				ft_reinit_pos(tmp, FALSE);
				tmp = tmp->prev;
				ft_remove_tetri(grid, tmp);
				ft_increment_pos(tmp, grid);
			}
			else
				tmp = tmp->next;
		}
		if (!tmp)
			break ;
		tmp = list->head;
		grid = ft_bigger_grid(grid);
	}
	return (grid);
}

int		ft_is_first_placeable(t_tetr *tetr)
{
	if (tetr->index == 0)
	{
		ft_reinit_pos(tetr, TRUE);
		return (FALSE);
	}
	return (TRUE);
}

void	ft_increment_pos(t_tetr *tetr, char **grid)
{
	tetr->pos_in_grid.x++;
	if (tetr->pos_in_grid.x == (int)ft_strlen(grid[0]) - 1)
	{
		tetr->pos_in_grid.x = 0;
		tetr->pos_in_grid.y++;
	}
}

void	ft_reinit_pos(t_tetr *tetr, int all)
{
	t_tetr	*tmp;

	tmp = tetr;
	while (tmp)
	{
		tmp->pos_in_grid.x = 0;
		tmp->pos_in_grid.y = 0;
		if (!all)
			tmp = NULL;
		else
			tmp = tmp->next;
	}
}
