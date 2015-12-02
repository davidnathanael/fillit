/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:49:51 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/02 16:03:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "check_file.h"

int	ft_check_file(int fd)
{
	char	*str;

	str = ft_file2str(fd);
	if (!str)
		return (NOT_VALID);
	return (VALID);
}

char	*ft_file2str(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		ft_putnbr(ret);
		ft_putchar('\n');
		if (ret < BUF_SIZE - 1)
			return (NULL);
		buf[ret] = '\0';
	}
	ft_putnbr(ret);
	return (ft_strdup("test"));
}
