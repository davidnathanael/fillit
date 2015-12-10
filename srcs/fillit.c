/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/10 22:27:10 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "check_file.h"
#include "check_tetri.h"
#include "tab2list.h"
#include "grid.h"
#include "is_placeable.h"
#include "libft.h"
#include <stdio.h>

void	ft_fillit(int fd)
{
	char	**tetr;
	char	**grid;
	t_list	*list = NULL;

	tetr = ft_check_file(fd);
	if (tetr == NULL)
		ft_putstr("error");
	list = ft_tab2list(tetr);
	grid = ft_smallest_grid(list->length);
	grid = ft_fill_grid(grid, list);
	ft_print_grid(grid);
}

char	**ft_fill_grid(char **grid, t_list *list)
{
	t_tetr	*tmp;
	int		placed;
	int		complete;

	tmp = list->head;
	placed = 0;
	complete = 0;
	while (!complete)
	{
		while (tmp)
		{
			placed = ft_is_placed(grid, tmp, tmp->pos_in_grid.x, tmp->pos_in_grid.y);
			//printf("%d | placed : %d\n", tmp->index, placed);
			if (!placed)
			{
				if (tmp->index == 0)
				{
					ft_reinit_pos(tmp);
					break ;
				}
				tmp->pos_in_grid.x = 0;
				tmp->pos_in_grid.y = 0;
				tmp = tmp->prev;
				ft_remove_tetri(grid, tmp);
				tmp->pos_in_grid.x++;
				if (tmp->pos_in_grid.x == (int)ft_strlen(grid[0]) - 1)
				{
					tmp->pos_in_grid.x = 0;
					tmp->pos_in_grid.y++;
				}
			}
			else
				tmp = tmp->next;
			//ft_print_grid(grid);
			//ft_putstr("\n-----------");
			//ft_putnbr((int)ft_strlen(grid[0]));
			//ft_putstr("---------------\n\n");
		}
		if (!tmp)
			break ;
		tmp = list->head;
		grid = ft_bigger_grid(grid);
	}
	return (grid);
}

void	ft_reinit_pos(t_tetr *tetr)
{
	t_tetr	*tmp;

	tmp = tetr;
	while (tmp)
	{
		tmp->pos_in_grid.x = 0;
		tmp->pos_in_grid.y = 0;
		tmp = tmp->next;
	}
}
