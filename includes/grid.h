/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:26:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/10 14:30:19 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

char	**ft_smallest_grid(int length);
char	**ft_bigger_grid(char **grid);
char	**ft_alloc_grid(int width);
int		ft_nearest_sqrt(int nb);

#endif
