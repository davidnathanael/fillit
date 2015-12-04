/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:24:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/04 18:29:21 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_tetri(t_list *list)
{
	t_list	*tmp;
	int		x;
	int		y;
	int		count;

	tmp = list;
	x = 1;
	y = 1;
	count = 0;
	while (tmp)
	{
		while (x != 4 && y != 4)
		{
			if (ft_browse_tetri(&x, &y, tmp->tetri, &count) == NOT_VALID)
				return (NOT_VALID);
		}
		if (count != 4)
			return (NOT_VALID);
		x = 1;
		y = 1;
		tmp = tmp->next;
	}
}

int	ft_browse_tetri(int *x, int *y, char **tetri, int *count)
{
	if (tetri[*y][*x] == '#'
			&& ft_check_around(*x, *y, tetri, *count) == NOT_VALID)
		return (NOT_VALID);
	if (tetri[*y][*x] == '#')
		(*count)++;
	if (*x == 4)
	{
		*x = 0;
		(*y)++;
		continue ;
	}
	(*x)++;
	return (VALID);
}

int	ft_check_around(int x, int y, char **tetri, int count)
{
	if (x < 4 && y < 4 && count < 4)
	{
		if (tetri[y][x + 1] != '#' && tetri[y + 1][x] != '#')
			return (NOT_VALID);
	}
	if (y == 4 && x != 4 && count < 4)
	{
		if (tetri[y][x + 1] != '#')
			return (NOT_VALID);
	}
	if (x == 4 && y != 4 && count < 4)
	{
		if (tetri[y + 1][x] != '#')
			return (NOT_VALID);
	}
	return (VALID);
}
