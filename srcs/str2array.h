/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:12:40 by adompe            #+#    #+#             */
/*   Updated: 2015/12/03 19:38:50 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR2ARRAY_H
# define STR2ARRAY_H

int		ft_count_tetriminos(char *);
char	**ft_set_tetriminos(char *str, char **tetriminos, int count);
char	**ft_alloc_tetriminos(int count);

#endif
