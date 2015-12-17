/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:58:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/15 16:03:57 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_TETRI_H
# define PLACE_TETRI_H
# include "tab2list.h"

int		ft_isplaced(char **grid, t_tetr *tetri, int x, int y);
int		ft_is_placeable(char **grid, t_tetr *tetri, int x, int y);
void	ft_place_tetri(char **grid, t_tetr *tetr, int x, int y);
void	ft_remove_tetri(char **grid, t_tetr *tetr);

void	ft_set_tetri_size(t_tetr *tetr, int count);
#endif
