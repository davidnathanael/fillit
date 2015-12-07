/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:24:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/07 14:04:57 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_tetri.h"
#include "check_file.h"
#include "tab2list.h"

int	ft_check_tetri(t_tetr *list)
{
	t_tetr	*tmp;
	int		x;
	int		y;
	int		count;

	tmp = list;
	x = 0;
	y = 0;
	count = 0;
	while (tmp)
	{
		while (x < 4 && y < 4)
		{
			printf("start | index_tetri : %d | y : %d | x : %d | count : %d \n", tmp->index, y, x, count);
			if (tmp->content[y][x] == '#')
			{
				printf("#\n");
				count++;
			}
			if (tmp->content[y][x] == '#'
					&& ft_check_around(x, y, tmp->content, count) == NOT_VALID)
			{
				return (NOT_VALID);
			}
			x++;
			if (x == 4)
			{
				printf("x == 4\n");
				x = 0;
				y++;
			}
			printf("end | index_tetri : %d | y : %d | x : %d | count : %d \n\n", tmp->index, y, x, count);
		}
		if (count != 4)
			return (NOT_VALID);
		count = 0;
		x = 0;
		y = 0;
		tmp = tmp->next;
	}
	return (VALID);
}
