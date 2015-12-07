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

<<<<<<< HEAD:includes/str2array.h
char	**ft_str2array(char *str);
int		ft_count_tetriminos(char *str);
char	**ft_set_tetriminos(char *str, char **tetriminos);
char	**ft_alloc_tetriminos(int count);
=======
# include "tab2list.h"

int		ft_check_tetri(t_tetr *list);
int		ft_browse_tetri(int *x, int *y, char **tetri, int *count);
int		ft_check_around(int x, int y, char **tetri, int count);
>>>>>>> 19ee9d4ce380177dcc74f0ca5779440dafd0aa28:includes/check_tetri.h

#endif
