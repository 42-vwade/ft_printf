/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 11:12:38 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define assign_type(t) ((t *)var)[0] = (t)va_arg(ap, t)

/*
**		FLOAT
*/

static FT_SIZE
	convert_f(t_format *o)
{
	size_t		ret;

	ret = 0;
	o->p.precision = !(o->p.tick & 0b100) ?  6 : o->p.precision;
	o->v = infinite_double(*(FT_LDBL*)o->v, o->p.precision);
	o->p.width = (LL)MAX(o->p.width - ft_strlen(o->v), 0);
	modify_o(o, "pad");
	ret = write(1, o->v, ft_strlen(o->v));
	free (o->v);
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
	o->v = n.d;
	if (o->v)
		ret = convert_f(o);
	return (ret);
}

int		parse_f(t_format *o)
{
	size_t	ret;

	ret = 0;
	o->v = (long double[1]){va_arg(o->arg, long double)};
	if ((ret = is_anomaly(*(double*)o->v, o)))
		return (ret);
	return (convert_f(o));
}
