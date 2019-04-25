/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 08:17:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		INT
*/

int		parse_i(va_list args, t_format *o)
{
	int		num;
	char	*pad;

	num = (int)va_arg(args, int);
	pad = (char *)ft_memchr(ft_strnew(o->p.precision), '0', o->p.precision);
	if ((0))
		num = o->count;
	o->str++;
	return (ft_intlen(num));
}

int		parse_u(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}
