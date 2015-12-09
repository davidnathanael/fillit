/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/09 13:35:37 by ddela-cr         ###   ########.fr       */
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
	ft_fill_grid(grid, list->head, ft_strlen(grid[0]));
}

void	ft_fill_grid(char **grid, t_tetr *tetri, int width)
{
	t_tetr	*tmp;
	int		i = 0;
	int		j = 0;
	int		placed;

	tmp = tetri;
	placed = -1;
	while (i < width && tmp)
	{
		printf("i : %d | j : %d | index : %d\n ", i, j, tmp->index);
		if ((placed = ft_is_placeable(grid, tmp, j, i)))
		{
			tetri->pos_in_grid.x = j;
			tetri->pos_in_grid.y = i;
			i = 0;
			j = 0;
			tmp = tmp->next;
			continue ;
		}
		printf("placed : %d\n", placed);
		j++;
		if (j == width)
		{
			j = 0;
			i++;
		}
		ft_print_grid(grid);
		ft_putstr("\n\n\n\n");
	}
	ft_print_grid(grid);
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
