/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:15:36 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 10:16:42 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "ft_printf.h"

/*
**  GLOBAL
*/

t_type  g_dispatch[] = {
    {'d', parse_i},
    {'i', parse_i},
    {'s', parse_s},
    {'c', parse_c},
    {'x', parse_x},
    {'u', parse_u},
    {'o', parse_o},
    {'p', parse_p},
    {'C', parse_C},
    {'S', parse_S},
    {'D', parse_D},
    {'X', parse_X},
	{0, NULL}
};

#endif
