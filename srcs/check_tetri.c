/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:24:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/21 17:12:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tetri.h"
#include "check_file.h"
#include "tab2list.h"
#include <stdlib.h>

int		ft_check_tetri(t_tetr *list)
{
	t_tetr	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_check_content(tmp->content, 0, 0) == NOT_VALID)
			return (NOT_VALID);
		free(tmp->content);
		tmp = tmp->next;
	}
	return (VALID);
}

int		ft_check_content(char **content, int x, int y)
{
	int		count;
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	count = 0;
	while (x <= 4 && y <= 4)
	{
		if (content[y][x] == '#')
		{
			count++;
			if (ft_check_cases(x, y, content, pos) == NOT_VALID)
				return (NOT_VALID);
			if (ft_check_double(x, y, content, pos) == NOT_VALID)
				return (NOT_VALID);
		}
		if (x == 4 && y < 4)
		{
			y++;
			x = -1;
		}
		x++;
	}
	if (count != 4)
		return (NOT_VALID);
	return (VALID);
}

int		ft_check_cases(int x, int y, char **tmp, t_pos *pos)
{
	if (y > 0)
		if (tmp[y - 1][x] == '#')
		{
			ft_set_pos_values(pos, x, y - 1);
			return (VALID);
		}
	if (x > 0)
		if (tmp[y][x - 1] == '#')
		{
			ft_set_pos_values(pos, x - 1, y);
			return (VALID);
		}
	if (y < 4)
		if (tmp[y + 1][x] == '#')
		{
			ft_set_pos_values(pos, x, y + 1);
			return (VALID);
		}
	if (x < 4)
		if (tmp[y][x + 1] == '#')
		{
			ft_set_pos_values(pos, x + 1, y);
			return (VALID);
		}
	return (NOT_VALID);
}

void	ft_set_pos_values(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

int		ft_check_double(int x, int y, char **tmp, t_pos *pos)
{
	if (y > 0 && pos->y > 0)
	{
		if ((tmp[y - 1][x] == '#' && y - 1 != pos->y) ||
			(tmp[pos->y - 1][pos->x] == '#' && pos->y - 1 != y))
			return (VALID);
	}
	if (x > 0 && pos->x > 0)
	{
		if ((tmp[y][x - 1] == '#' && x - 1 != pos->x) ||
			(tmp[pos->y][pos->x - 1] == '#' && pos->x - 1 != x))
			return (VALID);
	}
	if (y < 4 && pos->y < 4)
	{
		if ((tmp[y + 1][x] == '#' && y + 1 != pos->y) ||
			(tmp[pos->y + 1][pos->x] == '#' && pos->y + 1 != y))
			return (VALID);
	}
	if (x < 4 && pos->x < 4)
	{
		if ((tmp[y][x + 1] == '#' && x + 1 != pos->x) ||
			(tmp[pos->y][pos->x + 1] == '#' && pos->x + 1 != x))
			return (VALID);
	}
	return (NOT_VALID);
}
