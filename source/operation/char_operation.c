/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/31 00:50:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define ISU(c)	('A' <= (c) && (c) <= 'Z')

/*
**		CHAR
*/

static FT_SIZE
	convert_c(t_format *o)
{
	o->v = ISU(o->str[0]) ? encode_utf8((int[2]){*(ll_t *)o->v, 0}) :
		ft_strdup((char[]){*(ll_t *)o->v, 0});
	precision_s(o);
	width_o(o);
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

	o->v = &c;
	o->p.length = ISU(o->str[0]) ? ll : o->p.length;
	if (o->str[0] == '%')
		c = '%';
	else
		cast_o(o);
	return (convert_c(o));
}
