/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:46:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/07 14:08:50 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR2ARRAY_H
# define STR2ARRAY_H

typedef struct		s_tetr
{
	char			**content;
	char			letter;
	int				index;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

typedef struct		s_list
{
	unsigned int	length;
	t_tetr			*tail;
	t_tetr			*head;
}					t_list;

t_list	*ft_tab2list(char **tab);
char	**ft_tab2tetr(int line, char **tab);
t_list	*ft_list_append(t_list *list, char **tetr, char letter);

#endif
