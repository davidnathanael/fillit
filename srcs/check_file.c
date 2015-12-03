/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:49:51 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/03 14:00:27 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "check_file.h"

/*
** Checks if file format correct.
** Returns file converted in str if format is valid.
** Returns NULL if format is not valid.
*/

char	*ft_check_file(int fd)
{
	char	*str;

	str = ft_file2str(fd);
	if (!str || ft_check_chars(str) == NOT_VALID
			|| ft_check_format(str) == NOT_VALID)
		return (NULL);
	ft_putchar('\n');
	return (str);
}

char	*ft_file2str(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (ret <= 0)
		return (NULL);
	return (ft_strdup(buf));
}

/*
** Checks if str contains . or # or \n char only
** Returns VALID if true, else returns NOT_VALID
*/

int		ft_check_chars(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (NOT_VALID);
		str++;
	}
	return (VALID);
}

int		ft_check_format(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] && count <= TETR_SIZE)
	{
		if (str[i] == '\n')
		{
			if (str[i - 1] == '\n')
			{
				count = 1;
				i++;
				continue ;
			}
			if (count % 5 != 0)
				return (NOT_VALID);
		}
		count++;
		i++;
	}
	if (count != TETR_SIZE)
		return (NOT_VALID);
	return (VALID);
}
