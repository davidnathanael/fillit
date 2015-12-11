/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:42:53 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/11 02:31:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TRUE 1
# define FALSE 0

# define ERROR 1
# define NO_ERROR 0

# include "tab2list.h"

int		ft_fillit(int fd);
char	**ft_fill_grid(char **grid, t_list *list);
int		ft_is_first_placeable(t_tetr *tetr);
void	ft_increment_pos(t_tetr *tetr, char **grid);
void	ft_reinit_pos(t_tetr *tetr, int all);

#endif
