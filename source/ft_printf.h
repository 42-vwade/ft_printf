/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:19 by viwade            #+#    #+#             */
/*   Updated: 2019/04/15 20:19:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "ft_printf_structs.h"

int32_t get_params(t_format *object, t_param *set);
int		parse_c(va_list args, t_format *o);
int		parse_s(va_list args, t_format *o);
int		parse_i(va_list args, t_format *o);
int		parse_x(va_list args, t_format *o);
int		parse_u(va_list args, t_format *o);
int		parse_o(va_list args, t_format *o);
int		parse_p(va_list args, t_format *o);
int		parse_C(va_list args, t_format *o);
int		parse_S(va_list args, t_format *o);
int		parse_D(va_list args, t_format *o);
int		parse_X(va_list args, t_format *o);

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
	NULL
}

#endif
