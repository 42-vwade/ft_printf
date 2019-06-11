/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/11 00:19:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		CHAR
*/

static FT_SIZE
	convert_c(t_format *o)
{
	precision_s(o);
	width_o(o);
	append_o(&o->list, o->v, o->len = ft_strlen(o->v));
	return (o->len);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t is retrieved.
**	An uppercase specifier (C) is treated as if the length flag was given.
**	Otherwise, a null-terminated char is retrieved.
*/

int
	parse_c(t_format *o)
{
	ll_t	c;

	c = (int)(o->str[0] == '%' ? '%' : va_arg(o->ap, int));
	o->v = encode_utf8((int[2]){c, 0});
	return (convert_c(o));
}
