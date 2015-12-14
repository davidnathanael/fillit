/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:49:51 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/14 19:25:19 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "check_file.h"

char	**ft_check_file(int fd)
{
	char	*str;

	str = ft_file2str(fd);
	if (!str || ft_check_format(str) == NOT_VALID)
		return (NULL);
	return (ft_strsplit(str, '\n'));
}

char	*ft_file2str(int fd)
{
	int		ret;
	char	*str;
	char	buf[BUF_SIZE + 1];

	ret = read(fd, buf, BUF_SIZE);
	str = (char *)malloc(sizeof(char) * ret + 1);
	buf[ret] = '\0';
	if (ret <= 0)
		return (NULL);
	return (ft_strcpy(str, buf));
}

int		ft_is_valid_char(unsigned char c)
{
	if (c != '.' && c != '#' && c != '\n')
		return (NOT_VALID);
	return (VALID);
}

int		ft_check_format(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (ft_is_valid_char(str[i]) == NOT_VALID)
			return (NOT_VALID);
		if (count % 5 == 0 && str[i] != '\n')
			return (NOT_VALID);
		if (count == TETR_SIZE && str[count])
		{
			if (str[i] != '\n')
				return (NOT_VALID);
			count = 0;
		}
		count++;
		i++;
	}
	if (count != TETR_SIZE)
		return (NOT_VALID);
	return (VALID);
}
