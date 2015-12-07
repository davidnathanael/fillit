/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/07 17:28:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_file.h"
#include "check_tetri.h"
#include "tab2list.h"
#include "libft.h"
#include <stdio.h>

void	ft_fillit(int fd)
{
	char	**tetr;
	//t_list	*list = NULL;

	tetr = ft_check_file(fd);
	if (tetr == NULL)
		ft_putstr("error");
	//list = ft_tab2list(tetr);
}
