/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:47:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/04 22:13:01 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tab2list.h"
#include "libft.h"

t_list		*ft_tab2list(char **tab)
{
	t_list	*list;
	int		i;

	list = (t_list *)malloc(sizeof(t_list));
	i = 0;
	if (list != NULL)
	{
		list->length = 0;
		list->p_head = NULL;
		list->p_tail = NULL;
	}
	while (tab[i])
	{
		if (((i + 1) % 4) == 0)
		{
			list = ft_list_append(list, ft_tab2tetr(i, tab), (i + 1) / 4 + 'A');
		}
		i++;
	}
	return (list);
}

char	**ft_tab2tetr(int line, char **tab)
{
	int		start;
	int		i;
	char	**tetr;

	start = line - 3;
	i = 0;
	tetr = (char **)malloc(sizeof(char *));
	if (!tetr)
		return (NULL);
	while (i < 4)
	{
		tetr[i] = tab[start + i];
			i++;
	}
	return (tetr);
}

t_list *ft_list_append(t_list *list, char **tetr, char letter)
{
	t_tetr	*new_tetr;

	new_tetr = (t_tetr *)malloc(sizeof(t_tetr));
	(void)letter;
	if (!new_tetr)
		return (NULL);
	if (new_tetr != NULL)
	{
		printf("tetr : %s| \n", tetr[0]);
		printf("tetr : %s| \n", tetr[1]);
		printf("tetr : %s| \n", tetr[2]);
		printf("tetr : %s| \n", tetr[3]);
			new_tetr->content = tetr; // BUG HERE
		printf("content : %s| \n", new_tetr->content[0]);
		printf("content : %s| \n", new_tetr->content[1]);
		printf("content : %s| \n", new_tetr->content[2]);
		printf("content : %s| \n", new_tetr->content[3]);
		new_tetr->p_next = NULL;
		if (list->p_tail == NULL)
		{
			new_tetr->p_prev = NULL;
			list->p_head = new_tetr;
			list->p_tail = new_tetr;
		}
		else
		{
			list->p_tail->p_next = new_tetr;
			new_tetr->p_prev = list->p_tail;
			list->p_tail = new_tetr;
		}
		list->length++;
	}
	return (list);
}
