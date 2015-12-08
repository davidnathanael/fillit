/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 11:55:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_file.h"
#include "check_tetri.h"
#include "fill_tetri.h"
#include "opti_content.h"
#include "tab2list.h"
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
	printf("%d\n", ft_check_tetri(list->head));
	//AFFICHAGE LISTE
	t_tetr	*tmp = list->head;
	printf("length : %d\n", list->length);
	while (tmp)
	{
		printf("%s\n", tmp->content[0]);
		printf("%s\n", tmp->content[1]);
		printf("%s\n", tmp->content[2]);
		printf("%s\n\n", tmp->content[3]);
		tmp = tmp->next;
	}
	ft_opti_content(list->head);
	//ft_fill_tetri(list->head);
}
