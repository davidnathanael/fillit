/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:17:16 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/03 16:57:38 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str2array.h"
#include "libft.h"

char	**ft_str2array(char *str)
{
	int		count;
	char	**tetriminos;

	count = ft_count_tetriminos(str);
	tetriminos = (char **)malloc(sizeof(char *) * count + 1);
	return (NULL);
}

int		ft_count_tetriminos(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		if (*str == '\n' && *(str - 1) == '\n')
		{
			count++;
		}
	}
	count++;
	return (count);
}

char	**ft_set_tetriminos(char *str, char **tetriminos)
{
	(void)str;
	return (tetriminos);
}
