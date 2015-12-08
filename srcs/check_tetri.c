/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:24:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 10:47:50 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_tetri.h"
#include "check_file.h"
#include "tab2list.h"
#include <stdio.h>

int	ft_check_tetri(t_tetr *list)
{
	t_tetr	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (!ft_check_content(tmp->content))
		{
			return (NOT_VALID);
		}
		tmp = tmp->next;
	}
	return (VALID);
}

int	ft_check_content(char **content)
{
	int		x;
	int		y;
	int		count;
	x = 0;
	y = 0;
	count = 0;
	while (x <= 4 && y <= 4)
	{
		if (content[y][x] == '#')
		{
			count++;
			if (!ft_check_cases(x, y, content))
				return (0);
		}
		if (x == 4 && y < 4)
		{
			y++;
			x = -1;
		}
		x++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int	ft_check_cases(int x, int y, char **tmp)
{
	if (y > 0)
		if (tmp[y - 1][x] == '#')
			return (1);
	if (x > 0)
		if (tmp[y][x - 1] == '#')
			return (1);
	if (y < 4)
		if (tmp[y + 1][x] == '#')
			return (1);
	if (x < 4)
		if (tmp[y][x + 1] == '#')
			return (1);
	return (0);
}
