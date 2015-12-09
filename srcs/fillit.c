/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/09 17:53:17 by ddela-cr         ###   ########.fr       */
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
	ft_fill_grid(grid, list);
}

void	ft_fill_grid(char **grid, t_list *list)
{
	t_tetr	*tmp;
	int		placed;

	tmp = list->head;
	placed = 0;
	while (tmp)
	{
		placed = ft_is_placed(grid, tmp, tmp->pos_in_grid.x, tmp->pos_in_grid.y);
		tmp = tmp->next;
		ft_print_grid(grid);
		ft_putstr("\n--------------------------\n\n");
	}
}

void	ft_print_grid(char **grid)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(grid[0]);
	while (i < width)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}
