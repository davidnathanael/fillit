/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:09:08 by adompe            #+#    #+#             */
/*   Updated: 2015/12/07 23:40:49 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_tetri.h"
#include "tab2list.h"
#include "libft.h"
#include <stdlib.h>

void	ft_fill_tetri(t_tetr *tetri)
{
	t_tetr	*tmp;
	char	**final;

	final = ft_alloc_final();
	final = ft_include_content(tetri->content, final);
	tmp = tetri;
	ft_display_final(final);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
}

char	**ft_alloc_final()
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(26 * 4 * sizeof(char *));
	while (i < 26 * 4)
	{
		tmp[i] = (char *)malloc(26 * 4);
		i++;
	}
	return (tmp);
}

char	**ft_include_content(char **content, char **tab)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	tab = content;
	return (tab);
}

void	ft_display_final(char **tab)
{
	ft_putstr(tab[0]);
}
