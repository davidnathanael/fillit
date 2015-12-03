/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:26:09 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/03 21:12:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR2ARRAY_H
# define STR2ARRAY_H

char	**ft_str2array(char *str);
int		ft_count_tetriminos(char *str);
char	**ft_set_tetriminos(char *str, char **tetriminos);
char	**ft_alloc_tetriminos(int count);

#endif
