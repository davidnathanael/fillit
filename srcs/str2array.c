/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:17:16 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/03 20:46:49 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "str2array.h"
//#include "libft.h"

char	**ft_str2array(char *str)
{
	int		count;
	char	**tetriminos;

	count = ft_count_tetriminos(str);
	tetriminos = ft_alloc_tetriminos(count);
	return (ft_set_tetriminos(str, tetriminos, count));
}

int		ft_count_tetriminos(char *str)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = str;
	while (*tmp++)
	{
		if (*tmp == '\n' && *(tmp - 1) == '\n')
			count++;
	}
	count++;
	return (count);
}

char	**ft_set_tetriminos(char *str, char **tetriminos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		if (i == 20)
		{
			tetriminos[j][i] = '\0';
			i = 0;
			j++;
		}
		else
		{
			tetriminos[j][i] = str[k];
			i++;
		}
		k++;
	}
	tetriminos[j][i] = '\0';
	return (tetriminos);
}

char **ft_alloc_tetriminos(int count)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * count);
	while (i < count)
	{
		tmp[i] = (char *)malloc(sizeof(char) * 22);
		i++;
	}
	return (tmp);
}
