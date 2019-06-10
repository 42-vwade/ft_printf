/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/10 07:28:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

/*
**		STRING
*/

/*
**	Initializes return value to 0. Check for long conversion. Encode UTF8 or
**	copy string to memory. Get length of encoded string. Reduce length to
**	precision value, at most, if less than string length. Reduce value
**	of width by length value, with no less than 0 width.
**	Apply padding modifier. Write the prescribed string, free it, and retun
**	the number of bytes written.
*/

static FT_SIZE
	convert_s(t_format *o)
{
	precision_s(o);
	width_o(o);
	append_o(o->list, o->v, o->len = ft_strlen(o->v));
	return (o->len);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t * string is retrieved.
**	An uppercase specifier (S) is treated as if the length flag was given.
**	Otherwise, a null-terminated char * string is retrieved.
*/

int
	parse_s(t_format *o)
{
	if (!(o->v = va_arg(o->ap, void *)))
		o->v = "(null)";
	return (convert_s(o));
}
