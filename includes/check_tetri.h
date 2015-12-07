/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:25:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/07 12:59:57 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TETRI_H
# define CHECK_TETRI_H

# include "tab2list.h"

int		ft_check_tetri(t_tetr *list);
int		ft_browse_tetri(int *x, int *y, char **tetri, int *count);
int		ft_check_around(int x, int y, char **tetri, int count);

#endif
