/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 21:18:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/08 21:18:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_PLACEABLE_H
# define IS_PLACEABLE_H

int		ft_is_placeable(char **grid, t_pos *pos, int x, int y);
void	ft_place_tetri(char **grid, t_pos *pos, int x, int y);

#endif
