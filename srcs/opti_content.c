/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 23:41:18 by adompe            #+#    #+#             */
/*   Updated: 2015/12/08 00:40:55 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opti_content.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_tetr	*ft_opti_content(t_tetr *list)
{
	t_tetr	*tmp;

	tmp = list;
	while (tmp->next)
	{
		tmp->content = ft_condense(tmp->content);
		tmp = tmp->next;
	}
	return (tmp);
}

char	**ft_condense(char **content)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (content[y][x] == '.')
	{
		if (y == 3)
		{
			x++;
			y = -1;
		}
		y++;
	}
	printf("fisrt line : %s \n", content[0]);
	printf("First occurrence x: %d \n", x);
	y = 0;
	while (!ft_strcmp(content[y], "....") || y > 4)
		y++;
	printf("First occurrence y: %d \n", y);
	return (content);
}

char	**ft_condense_width(int x, char **tab)
{
	int	i;
	int	j;

	i = x;
	j = 0;
	while (i > 0)
	{
		tab[j][i - 1] = tab[j][i];
		j++;
		if (j > 4)
		{
			i--;
			j = 0;
		}
	}
	return (tab);
}
