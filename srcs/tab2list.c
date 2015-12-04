/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:47:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/05 00:37:25 by ddela-cr         ###   ########.fr       */
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

	list = (t_list *)malloc(sizeof(t_list)); //allocation liste
	i = 0;
	if (list != NULL) // initialisation list
	{
		list->length = 0;
		list->p_head = NULL;
		list->p_tail = NULL;
	}
	while (tab[i]) //parcourt tab, contenant toutes les lignes. i = ligne
	{
		if (((i + 1) % 4) == 0) //si ligne est multiple de 4
			list = ft_list_append(list, ft_tab2tetr(i, tab), i / 4 + 'A');
			//cree nouvel element t_tetr a la fin de la liste
			//check tab2list.h pour comprendre
		i++;
	}
	return (list);
}
//prend les 4 lignes correspondant a un tetriminos et transforme
//en un tableau a deux dimensions.
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
		tetr[i] = tab[start + i];//tab deja allouer donc pas de copie char par char
		i++;
	}
	return (tetr);
}

t_list *ft_list_append(t_list *list, char **tetr, char letter)
{
	t_tetr	*new_tetr;

	new_tetr = (t_tetr *)malloc(sizeof(t_tetr)); //malloc nouvel element t_tetr,
	if (!new_tetr)
		return (NULL);
	if (new_tetr != NULL)
	{
		printf("tetr : %s| \n", tetr[0]); //debug de tetr, recu en parametre
		printf("tetr : %s| \n", tetr[1]);
		printf("tetr : %s| \n", tetr[2]);
		printf("tetr : %s| \n", tetr[3]);
			new_tetr->content = tetr; // BUG HERE
			new_tetr->letter = letter;
		printf("letter: %c| \n", letter);
		printf("content : %s| \n", new_tetr->content[0]); //debug apres avoir ete copie
		printf("content : %s| \n", new_tetr->content[1]); //fais ./fillit sample
		printf("content : %s| \n", new_tetr->content[2]); //la 3eme ligne deconne
		printf("content : %s| \n", new_tetr->content[3]); //pb surement lors du malloc
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
