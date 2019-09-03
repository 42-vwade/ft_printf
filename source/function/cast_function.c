/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 06:10:12 by viwade            #+#    #+#             */
/*   Updated: 2019/07/30 09:08:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	cast_o(t_format *o)
{
	*((ull_t *)o->v) = va_arg(o->ap, ull_t) & (~0 >> (64 - o->p.length * 8));
}

/*
**	#define U_VLS(u)	((u)!='d'||(u)!='i')
**	->ap, o->v, &o->p, U_VLS(ft_tolower(o->str[0]))
**	cast_o(va_list ap, ll_t *n, t_param *parm, int u)
**	cast_o(t_format *o)
**	{
**	char	u;
**	ll_t	*n;
****	n = o->v;
**	u = U_VLS(ft_tolower(o->str[0]));
**	IF_E(!o->p.length,
**	n[0] = u ? (ull_t)(uint)va_arg(o->ap, int) : (ll_t)(int)va_arg(o->ap, int),
**	IF_E(o->p.length & hh,
**	n[0] = u ? (ull_t)(uc_t)va_arg(o->ap, int) : (ll_t)(char)va_arg(o->ap, int),
**	IF_E(o->p.length & h, n[0] = u ?
**		(ull_t)(us_t)va_arg(o->ap, int) : (ll_t)(short)va_arg(o->ap, int),
**	IF_E(o->p.length & l,
**	n[0] = u ? (ull_t)va_arg(o->ap, long) : (ll_t)va_arg(o->ap, long),
**	IF_E(o->p.length & ll,
**	n[0] = u ? (ull_t)va_arg(o->ap, ull_t) : (ll_t)va_arg(o->ap, ll_t),
**	IF_E(o->p.length & j,
**	n[0] = u ? (ull_t)va_arg(o->ap, uintmax_t) : (ll_t)va_arg(o->ap, intmax_t),
**	IF_C(o->p.length & z || o->p.length & t,
**	n[0] = u ? (ull_t)va_arg(o->ap, size_t)
**		: (ll_t)va_arg(o->ap, ssize_t))))))));
**	IF_E(u, o->p.flags &= ~neg, o->p.flags |= (n[0] < 0) * neg);
**	return ;
**	}
*/
