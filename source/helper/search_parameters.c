/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:49:18 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 02:07:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static void
	search_flags(ull_t *set, const char *f, size_t *len, size_t *i)
{
	set[0] = 0;
	while (*i < *len || (*i = 0))
	{
		if (('1' <= f[*i] && f[*i] <= '9') || f[*i] == '.')
			break ;
		MATCH(f[*i] == '+', set[0] = (set[0] | plus) & ~(space));
		OR(f[*i] == '-', set[0] = (set[0] | minus) & ~(zero));
		OR(f[*i] == '0', set[0] |= !(minus & set[0]) << 2);
		OR(f[*i] == '#', set[0] |= 1 << 3);
		OR(f[*i] == ' ', set[0] |= !(plus & set[0]) << 4);
		ELSE(*i = *i + 1);
	}
	while (*i < *len && (('0' <= f[*i] && f[*i] <= '9') || f[*i] == '.'))
		*i = *i + 1;
	while (*i < *len || (*i = 0))
	{
		MATCH(f[*i] == '+', set[0] = (set[0] | plus) & ~(space));
		OR(f[*i] == '-', set[0] = (set[0] | minus) & ~(zero));
		OR(f[*i] == '0', set[0] |= !(minus & set[0]) << 2);
		OR(f[*i] == '#', set[0] |= 1 << 3);
		OR(f[*i] == ' ', set[0] |= !(plus & set[0]) << 4);
		ELSE(*i = *i + 1);
	}
}

static int
	search_width(ull_t *w, const char *f, size_t *len, size_t *i)
{
	w[0] = 0;
	while (*i < *len && !('1' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	MATCH(f[*i] == '*', RET(1));
	OR(ft_isdigit(f[*i]), w[0] = ft_atoi(&f[*i]));
	while (*i < *len && ('0' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	RET(0);
}

static int
	search_precision(ull_t *p, const char *f, size_t *len, size_t *i)
{
	p[0] = 0;
	MATCH(f[*i] != '.', RET(0));
	ELSE(*i = *i + 1);
	MATCH(f[*i] == '*', RET(1));
	OR(ft_isdigit(f[*i]), p[0] = ft_atoi(&f[*i]));
	while (*i < *len && ('0' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	RET(0);
}

void
	search_parameters(t_format *o, const char *format)
{
	size_t	i;

	i = 0;
	search_flags(&o->p.flags, format, &o->len, &i);
	if (search_width(&o->p.width, format, &o->len, &i))
		o->p.width = va_arg(o->ap, int);
	o->p.tick &= !!o->p.flags << 0;
	o->p.tick |= !!o->p.width << 1;
	o->p.tick |= (format[i] == '.') << 2;
	if (search_precision(&o->p.precision, format, &o->len, &i))
		o->p.precision = va_arg(o->ap, int);
	search_length(&o->p.width, format, &o->len, &i);
	o->p.tick |= !!o->p.length << 3;
}
