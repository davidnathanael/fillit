/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 21:18:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/09 14:52:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_PLACEABLE_H
# define IS_PLACEABLE_H

# include "tab2list.h"

int		ft_is_placed(char **grid, t_tetr *tetri, int x, int y);
int		ft_is_placeable(char **grid, t_tetr *tetri, int x, int y);
void	ft_place_tetri(char **grid, t_tetr *tetr, int x, int y);
void	ft_remove_tetri(char **grid, t_tetr *tetr);

#endif
