/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 18:22:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_file.h"
#include "check_tetri.h"
#include "fill_tetri.h"
#include "opti_content.h"
#include "tab2list.h"
#include "grid.h"
#include "libft.h"
#include <stdio.h>

void	ft_fillit(int fd)
{
	char	**tetr;
	t_list	*list = NULL;

	tetr = ft_check_file(fd);
	if (tetr == NULL)
		ft_putstr("error");
	list = ft_tab2list(tetr);
	printf("x : %d | y : %d\n", list->head->pos[0].x, list->head->pos[0].y);
	printf("x : %d | y : %d\n", list->head->pos[1].x, list->head->pos[1].y);
	printf("x : %d | y : %d\n", list->head->pos[2].x, list->head->pos[2].y);
	printf("x : %d | y : %d\n", list->head->pos[3].x, list->head->pos[3].y);
	//ft_opti_content(list->head);
	//ft_fill_tetri(list->head);
}
