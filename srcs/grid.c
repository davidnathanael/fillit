/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:09:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/11 00:59:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "libft.h"

char **ft_smallest_grid(int length)
{
	int		nb_blocs;
	int		width;
	char	**grid;

	nb_blocs = 4 * length;
	width = 0;
	while (width * width < nb_blocs)
		width++;
	grid = ft_alloc_grid(width);
	return (grid);
}

char **ft_bigger_grid(char **grid)
{
	int	width;

	width = (int)ft_strlen(grid[0]) + 1;
	free(grid);
	grid = NULL;
	grid = ft_alloc_grid(width);
	return (grid);
}

char	**ft_alloc_grid(int width)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char *) * width);
	while (i < width)
	{
		grid[i] = (char *)malloc(sizeof(char) * width + 1);
		while (j < width)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
	return (grid);
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

void	ft_empty_grid(char **grid)
{
	int	width;

	width = ft_strlen(grid[0]);
	free(grid);
	grid = ft_alloc_grid(width);
}
