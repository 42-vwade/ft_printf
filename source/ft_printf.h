/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:19 by viwade            #+#    #+#             */
/*   Updated: 2019/04/14 04:12:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "ft_printf_structs.h"

int32_t get_params(t_format *object, t_param *set);

/*
**  GLOBAL
*/

t_type  g_dispatch[] = {
    {'d', int_parse},
    {'d', int_parse},
    {'s', str_parse},
    {'c', char_parse},
    {'x', x_parse},
    {'u', u_parse},
    {'o', o_parse},
    {'p', p_parse},
    {'C', c_wide_parse},
    {'S', s_wide_parse},
    {'D', d_wide_parse},
    {'X', x_wide_parse}
}

#endif
