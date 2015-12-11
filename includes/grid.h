/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:26:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/11 00:59:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

char	**ft_smallest_grid(int length);
char	**ft_bigger_grid(char **grid);
char	**ft_alloc_grid(int width);
void	ft_print_grid(char **grid);
void	ft_empty_grid(char **grid);

#endif
