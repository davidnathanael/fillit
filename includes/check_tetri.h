/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:25:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/21 16:35:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TETRI_H
# define CHECK_TETRI_H
# include "tab2list.h"

int		ft_check_tetri(t_tetr *list);
int		ft_check_content(char **content, int x, int y);
int		ft_check_cases(int x, int y, char **tmp, t_pos *pos);
void	ft_set_pos_values(t_pos *pos, int x, int y);
int		ft_check_double(int x, int y, char **tmp, t_pos *pos);

#endif
