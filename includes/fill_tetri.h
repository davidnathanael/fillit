/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:21:52 by adompe            #+#    #+#             */
/*   Updated: 2015/12/07 23:29:15 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_TETRI_H
# define FILL_TETRI_H

# include "tab2list.h"

void	ft_fill_tetri(t_tetr *tetri);
char	**ft_alloc_final();
char	**ft_include_content(char **content, char **tab);
void	ft_display_final(char **tab);

#endif
