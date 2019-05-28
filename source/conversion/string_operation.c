/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/27 23:33:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"
#define return_type(ap, type) ({(type) t = (type)va_arg(ap, type);)})

/*
**		STRING
*/

/*
**	Convert incoming array to int array. Allocation required.
**	Free allocated int array.
*/
static int
	write_wstr(void *data)
{
	size_t		len;
	t_format	*o;

	o = data;
	o->v = wstr_to_ustr(o->v);
	if (o->p.precision <= 0)
		return (0);
	len = MIN(ft_lstrlen(o->v), o->p.precision);
	o->count += print_utf8_n(o->v, len);
	free(o->v);
	return ((int)len);
}

static int
	write_str(t_format *data)
{
	t_format	*o;

	o = data;
	if (((t_format*)o)->p.precision <= 0)
		return (0);
	return (write(1, o->v, MIN(ft_strlen(o->v), ((t_format*)o)->p.precision)));
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
	o->v = va_arg(o->arg, void *);
	if (!o->v)
		return (write(1, "(null)", 6));
	if ((int)o->p.precision == -1)
		o->p.precision = 0;
	if (o->p.length == 1 << 2 || ft_isuppercase(o->str[0]))
		return(pad_o(o, write_wstr, MAX(o->p.width - ft_lstrlen(o->v), 0)));
	else
		return(pad_o(o, write_str, MAX(o->p.width - ft_strlen(o->v), 0)));
}

