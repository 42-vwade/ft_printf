/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/17 00:48:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PLUS(n) ((n) & (1 << 0))
#define MINUS(n) ((n) & (1 << 1))
#define ZERO(n) ((n) & (1 << 2))
#define HASH(n) ((n) & (1 << 3))
#define SPACE(n) ((n) & (1 << 4))
#define U_HH(n)	n = (unsigned char)(n)
#define U_H(n)	n = (unsigned short)(n)
#define U_L(n)	n = (unsigned long)(n)
#define U_LL(n)	n = (unsigned long long)(n)
#define CHH(a)	(a & hh)
#define CH(a)	(a & h)
#define CL(a)	(a & l)
#define CLL(a)	(a & ll)
#define U_LENGTH(a, n, t)	if(a){t}else{n = (unsigned)n;}

/*
**		OCTAL / HEX
*/

static FT_SIZE
	convert_x(t_format *o)
{
	char	u;
	u = ft_tolower(o->str[0]) == 'b' ? 2 : 16 >> (ft_tolower(o->str[0]) == 'o');
	o->v = ft_itoa_base(*(ull_t*)o->v, u);
	precision_i(o);
	width_o(o);
	append_o(&o->list, o->v, o->len = ft_strlen(o->v));
	return (o->len);
}

static void
	cast_x(va_list ap, ull_t *n, ull_t lm, int u)
{
	if (!lm)
		n[0] = (unsigned int)va_arg(ap, int);
	else if (lm & hh)
		n[0] = (unsigned char)va_arg(ap, int);
	else if (lm & h)
		n[0] = (unsigned short)va_arg(ap, int);
	else if (lm & l)
		n[0] = (unsigned long)va_arg(ap, long);
	else if (lm & ll)
		n[0] = (unsigned long long)va_arg(ap, long long);
	else if (lm & j)
		n[0] = u ? va_arg(ap, uintmax_t) : va_arg(ap, intmax_t);
	else if (lm & z || lm & t)
		n[0] = u ? va_arg(ap, size_t) : va_arg(ap, ssize_t);
}

/*
**	Conditions already taken care of.
**	Input specifier shall be o / O / x / X / p / P
**	Output shall be in in either base 16, or base 8 if o / O is given
*/

int		parse_x(t_format *o)
{

	ull_t	num;

	o->v = &num;
	if (ft_tolower(o->str[0]) == 'p')
	{
		num = (intptr_t)va_arg(o->ap, intptr_t);
		o->p.flags |= hash;
	}
	else
		cast_x(o->ap, o->v, o->p.length, 1);
	return (convert_x(o));
}
