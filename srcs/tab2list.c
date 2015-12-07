/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:47:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/07 13:05:29 by ddela-cr         ###   ########.fr       */
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
		list->head = NULL;
		list->tail = NULL;
	}
	while (tab[i])
	{
		if (((i + 1) % 4) == 0)
		{
			list = ft_list_append(list, ft_tab2tetr(i, tab), i / 4 + 'A');
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
	tetr = (char **)malloc(sizeof(char *) * 4);
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
	if (!new_tetr)
		return (NULL);
	if (new_tetr != NULL)
	{
			new_tetr->content = tetr;
			new_tetr->letter = letter;
		new_tetr->next = NULL;
		if (list->tail == NULL)
		{
			new_tetr->prev = NULL;
			list->head = new_tetr;
			list->tail = new_tetr;
		}
		else
		{
			list->tail->next = new_tetr;
			new_tetr->prev = list->tail;
			list->tail = new_tetr;
		}
		list->length++;
	}
	return (list);
}
