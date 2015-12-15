/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:29:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/15 16:04:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tab2list.h"
#include "libft.h"
#include "place_tetri.h"

t_list	*ft_tab2list(char **tab)
{
	t_list	*list;
	int		i;

	list = (t_list *)malloc(sizeof(t_list));
	i = 0;
	if (list != NULL)
	{
		list->length = 0;
		list->head = NULL;
		list->tail = NULL;
	}
	while (tab[i])
	{
		if (((i + 1) % 4) == 0)
		{
			list = ft_list_append(list, ft_tab2tetr(i, tab), i / 4);
		}
		i++;
	}
	return (list);
}

char	**ft_tab2tetr(int line, char **tab)
{
	int		start;
	int		i;
	char	**tetr;

	start = line - 3;
	i = 0;
	tetr = (char **)malloc(sizeof(char *) * 4);
	if (!tetr)
		return (NULL);
	while (i < 4)
	{
		tetr[i] = tab[start + i];
		i++;
	}
	return (tetr);
}

t_list	*ft_list_append(t_list *list, char **tetr, char index)
{
	t_tetr	*new_tetr;

	new_tetr = (t_tetr *)malloc(sizeof(t_tetr));
	if (new_tetr != NULL)
	{
		new_tetr->content = tetr;
		new_tetr->index = index;
		new_tetr->letter = index + 'A';
		ft_set_positions(new_tetr);
		new_tetr->next = NULL;
		if (list->tail == NULL)
		{
			new_tetr->prev = NULL;
			list->head = new_tetr;
			list->tail = new_tetr;
		}
		else
		{
			list->tail->next = new_tetr;
			new_tetr->prev = list->tail;
			list->tail = new_tetr;
		}
		list->length++;
	}
	return (list);
}

void	ft_set_positions(t_tetr *tetr)
{
	char	**grid;
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	grid = tetr->content;
	tetr->pos = (t_pos *)malloc(sizeof(t_pos) * 4);
	tetr->pos_in_grid.x = 0;
	tetr->pos_in_grid.y = 0;
	while (grid[y][x] != '#' && y < 4 && x < 4)
	{
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
	ft_set_positions_bis(tetr, x, y);
}

void	ft_set_positions_bis(t_tetr *tetr, int x, int y)
{
	int	i;
	int	j;
	int	count;

	i = y;
	j = x;
	count = 0;
	tetr->pos[0].x = 0;
	tetr->pos[0].y = 0;
	while (i < 4 && j < 4 && count != 4)
	{
		if (tetr->content[i][j] == '#')
		{
			tetr->pos[count].x = j - x;
			tetr->pos[count].y = i - y;
			count++;
		}
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	ft_set_tetri_size(tetr, 0);
}
