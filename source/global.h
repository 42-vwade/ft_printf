/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:15:36 by viwade            #+#    #+#             */
/*   Updated: 2019/05/21 07:27:23 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "ft_printf.h"
# define CONV1 {'S',parse_s},{'D',parse_i},{'O',parse_o},{'U',parse_u}
# define CONV2 {'E',parse_e},{'F',parse_f},{'G',parse_g},{'A',parse_a}
# define CONV3 {'e',parse_e},{'n',parse_n},{'g',parse_g},{'a',parse_a}
# define BONUS_CONV CONV1,CONV2,CONV3

/*
**  GLOBAL
**	CONVERSIONS
**		csp / diouxX / f / %
**	CONVERSIONS --	REMAINING
**		 efga / DOUEFGA / n%	<<	diuoxXfFeEgGaAcspn%
*/

t_type	g_dispatch[] = {
	{'c', parse_c},
	{'s', parse_s},
	{'p', parse_hex},
	{'d', parse_i},
	{'i', parse_i},
	{'u', parse_u},
	{'o', parse_o},
	{'x', parse_hex},
	{'X', parse_hex},
	{'f', parse_f},
	{'C', parse_c},
	{'S', parse_s},
	{0, NULL}
};

#endif
