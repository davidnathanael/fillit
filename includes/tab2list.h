/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:46:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/04 22:12:35 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR2ARRAY_H
# define STR2ARRAY_H

typedef struct		/
{
	char			**content;
	char			letter;
	struct s_tetr	*p_next;
	struct s_tetr	*p_prev;
}					t_tetr;

typedef struct		s_list
{
	unsigned int	length;
	t_tetr			*p_tail;
	t_tetr			*p_head;
}					t_list;
t_list	*ft_tab2list(char **tab);
char	**ft_tab2tetr(int line, char **tab);
t_list	*ft_list_append(t_list *list, char **tetr, char letter);

#endif
