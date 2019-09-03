/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:39:52 by viwade            #+#    #+#             */
/*   Updated: 2019/09/02 20:09:40 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static char
	*format_convert(const char *format, size_t *i)
{
	t_format	o;

	ft_bzero(&o, sizeof(o));
	i[0] += find_specifier(format);
}

static size_t
	find_next(const char *s)
{
	const char *e;

	e = s;
	while (e[0] && e[0] != '%')
		e++;
	return (e - s);
}

static void
	create_string(t_format *o, const char *format)
{
	size_t	i;
	size_t	tonext;
	char *output;

	i = 0;
	if (!(output = ft_strnew(0)))
		ft_error("failed to allocate output string");
	while (format[i])
	{
		if (tonext = find_next(&format[i]))
			i += tonext;
		if (tonext &&
			!(output = ft_strjoin_free(output, ft_strsub(format, i, tonext))))
			ft_error("failed to append output string");
		if (format[i] && format[i] == '%' &&
			!(output = ft_strjoin_free(output, format_convert(&format[i], &i))))
			ft_error("failed to append output string");
	}
}

int
	ft_vprintf(const char *format, va_list ap)
{
	t_format	o;

	ft_bzero(&o, sizeof(o));
	create_string(&o, o.str = (char *)format);
	o.count = write(1, o.str, ft_strlen(o.str));
	ft_memdel(&o.str);
	return (o.count);
}

/*
**	int
**		ft_vprintf(const char *format, va_list ap)
**	{
**		t_format	o;
**
**		ft_bzero(&o, sizeof(o));
**		va_copy(o.ap, ap);
**		parse_input(&o, o.str = (char *)format);
**		va_end(o.ap);
**		return (o.count);
**	}
*/
