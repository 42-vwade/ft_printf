/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/05 22:04:34 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define U_VLS(u) ((u)=='o'||(u)=='u'||(u)=='x')
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define LENGTH(t) {t}

/*
**		INT
*/

static FT_STR
	zero_i(char *s, ull_t pad)
{
	char	*z;

	if (!pad)
		return (s);
	z = ft_memset(ft_strnew(pad + 1), '0', pad);
	return (ft_strjoin_free(z, s));
}

static int
	convert_i(t_format *o)
{
	char	u[4];
	size_t	ret;

	ret = 0;
	u[0] = (o->p.length & (l + ll) || ft_isuppercase(o->str[0]));
	u[1] = ft_tolower(o->str[0]) == 'u';
	o->v = u[1] ? ft_itoa_unsigned(*(ull_t*)o->v) : ft_itoa(*(int64_t*)o->v);
	if (o->p.tick & 4)
		o->v = zero_i(o->v, MAX(o->p.precision - ft_strlen(o->v), 0));
	o->p.width = MAX((ll_t)(o->p.width - ft_strlen(o->v)), 0);
	modify_o(o, "sign");
	modify_o(o, "pad");
	ret = write(1, o->v, ft_strlen(o->v));
	free(o->v);
	return (ret);
}

static void
	cast_i(ull_t *n, ull_t lm, int u)
{
	if (!lm)
		n[0] = (int)n[0];
	else if (lm & hh)
		n[0] = (char)n[0];
	else if (lm & h)
		n[0] = (short)n[0];
	else if (lm & l)
		n[0] = (long)n[0];
	else if (lm & ll)
		n[0] = (long long)n[0];
	else if (lm & j)
		n[0] = u ? (uintmax_t)n[0] : (intmax_t)n[0];
	else if (lm & z || lm & t)
		n[0] = u ? (size_t)n[0] : (ssize_t)n[0];
}

int
	parse_i(t_format *o)
{
	int64_t	num;

	num = va_arg(o->arg, int64_t);
	o->v = &num;
	cast_i(o->v, o->p.length, U_VLS(ft_tolower(o->str[0])));
	o->p.flags |= (!U_VLS(o->str[0]) && num < 0) ? neg : 0;
	return (convert_i(o));
}
