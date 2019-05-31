/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 13:27:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"
#define return_type(ap, type) ({(type) t = (type)va_arg(ap, type);)})

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
	char	u;
	size_t	ret;
	size_t	len;

	ret = 0;
	u = (o->p.length & (l + ll) || ft_isuppercase(o->str[0]));
	o->v = u ? encode_utf8((void *)wstr_to_ustr(o->v)) : ft_strdup(o->v);
	len = ft_strlen(o->v);
	len = o->p.tick & 0b0100 ? MIN(len, o->p.precision) : len;
	o->p.width = MAX((LL)(o->p.width - len), 0);
	modify_o(o, "pad");
	ret = write(1, o->v, len + o->p.width);
	free(o->v);
	return (ret);
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
	if (!(o->v = va_arg(o->arg, void *)))
		o->v = "(null)";
	return (convert_s(o));
}

