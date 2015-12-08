/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:42:53 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 23:16:58 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "tab2list.h"

void	ft_fillit(int fd);
void	ft_fill_grid(char **grid, t_tetr *tetri, int width);
void	ft_print_grid(char **grid);

#endif
