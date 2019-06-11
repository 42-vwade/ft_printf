/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/11 16:44:40 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define U_VLS(u) ((u)=='o'||(u)=='u'||(u)=='x')
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define VA_ASN(type)	va_arg(ap, type)
#define VA_I(t,a,u)	((u)?(t)va_arg(a,int):(unsigned t)va_arg(a,int))
#define VA_U(t,a,u)	((u)?(t)va_arg(a,t):(unsigned t)va_arg(a,t))

/*
**		INT
*/

/*
**		Zero Pad Integer.
**	#.	If [precision] given && if [precision] > [value].length
**			Set total [precision] = [precision] - [value].length, max 0
**		[zero] prepend number with [precision] # of '0' characters
**		<Character> Pad String.
*/

static int
	convert_i(t_format *o)
{
	char	u[4];

	u[0] = (o->p.length & (l + ll) || ft_isuppercase(o->str[0]));
	o->v = ft_tolower(o->str[0]) == 'u' ?
		ft_itoa_unsigned(*(ull_t*)o->v) : ft_itoa(*(ll_t*)o->v);
	precision_i(o);
	width_o(o);
	append_o(&o->list, o->v, o->len = ft_strlen(o->v));
	return (o->len);
}

static void
	cast_i(va_list ap, ull_t *n, ull_t lm, int u)
{
	if (!lm)
		n[0] = VA_U(int, ap, u);
	else if (lm & hh)
		n[0] = VA_I(char, ap, u);
	else if (lm & h)
		n[0] = VA_I(short, ap, u);
	else if (lm & l)
		n[0] = VA_U(long, ap, u);
	else if (lm & ll)
		n[0] = VA_U(long long, ap, u);
	else if (lm & j)
		n[0] = u ? va_arg(ap, uintmax_t) : va_arg(ap, intmax_t);
	else if (lm & z || lm & t)
		n[0] = u ? va_arg(ap, size_t) : va_arg(ap, ssize_t);
}

/*
**	1.	64-bit signed placeholder variable. Signage enables negative check.
**	3.	Assign address of placeholder to object. For later modification.
**	4.	Get appropriate value based on length specifier.
**	5.	Check if value is unsigned && value is negative.
**		Positive integer values do not matter.
**	6.	Send object to conversion task. Return number of characters written.
*/

int
	parse_i(t_format *o)
{
	int64_t	num;

	o->v = &num;
	cast_i(o->ap, o->v, o->p.length, U_VLS(ft_tolower(o->str[0])));
	o->p.flags |= (!U_VLS(ft_tolower(o->str[0])) && num < 0) ? neg : 0;
	return (convert_i(o));
}
