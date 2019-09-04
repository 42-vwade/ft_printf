/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 01:20:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		FLOAT
*/

static FT_SIZE
	convert_f(t_format *o)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	o->p.precision = !(o->p.tick & 0b100) ? 6 : o->p.precision;
	o->v = infinite_double(*(double*)o->v, o->p.precision);
	len = ft_strlen(o->v);
	o->p.width = MAX((LL)(o->p.width - len), 0);
	if (o->p.flags & (plus + space + neg))
		modify_o(o, "sign");
	else
		modify_o(o, "pad");
	ret = write(1, o->v, ft_strlen(o->v));
	free(o->v);
	return (ret);
}

static int
	is_anomaly(long double num, t_format *o)
{
	size_t	ret;
	FT_NBR	n;

	ret = 0;
	n.d = NULL;
	if ((n.length = (num != num) * 3))
		n.d = ft_strdup("nan");
	else if ((n.length = (num == INFINITY) * 3))
		n.d = ft_strdup("inf");
	else if ((n.length = (num == -INFINITY) * 4))
		n.d = ft_strdup("-inf");
	if (n.d && (o->v = n.d))
		ret = convert_f(o);
	if (n.d)
		free(n.d);
	return (ret);
}

int		parse_f(t_format *o)
{
	size_t	ret;
	double	num;

	ret = 0;
	o->v = &num;
	num = va_arg(o->ap, double);
	o->p.flags |= (num < 0) << 7;
	if ((ret = is_anomaly(*(double*)o->v, o)))
		return (ret);
	return (convert_f(o));
}
