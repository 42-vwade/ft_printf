/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/16 00:47:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		FLOAT
*/

static FT_SIZE
	convert_f(t_format *o)
{
	precision_f(o);
	width_o(o);
	return (o->len);
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
	{
		ft_bzero(&o->p.flags, sizeof(o->p.flags));
		o->len = n.length;
		width_o(o);
		ret = n.length;
	}
	if (n.d)
		free(n.d);
	return (ret);
}

int		parse_f(t_format *o)
{
	size_t	ret;
	double	db;
	ld_t	ldb;

	ret = 0;
	IF_E(o->p.length & LD,
		o->v = &ldb,
		o->v = &db);
	IF_E(o->p.length & LD,
		ldb = va_arg(o->ap, ld_t),
		db = va_arg(o->ap, db_t));
	o->p.flags |= (o->p.length & LD ? ldb < 0 : db < 0) << 7;
	if ((ret = is_anomaly(*(ld_t*)o->v, o)))
		return (ret);
	return (convert_f(o));
}
