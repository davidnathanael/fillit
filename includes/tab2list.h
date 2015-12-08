/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:46:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 17:35:04 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB2LIST_H
# define TAB2LIST_H

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tetr
{
	char			**content;
	char			letter;
	int				index;
	t_pos			*pos;
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
t_list	*ft_list_append(t_list *list, char **tetr, char index);
void	ft_set_positions(t_tetr *tetr);
void	ft_set_positions_bis(t_tetr *tetr, int x, int y);

#endif
