/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_content.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 23:43:58 by adompe            #+#    #+#             */
/*   Updated: 2015/12/07 23:56:35 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTI_CONTENT_H
# define OPTI_CONTENT_H

# include "tab2list.h"

t_tetr	*ft_opti_content(t_tetr *list);
char	**ft_condense(char **content);
char	**ft_condense_width(int x, char **tab);

#endif
