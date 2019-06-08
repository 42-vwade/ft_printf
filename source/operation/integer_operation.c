/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/07 20:07:17 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define U_VLS(u) ((u)=='o'||(u)=='u'||(u)=='x')
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define VA_ASN(type)	va_arg(ap, type)
#define LENGTH(t) {t}

/*
**		INT
*/

static FT_STR
	zero_i(t_format *o, ull_t pad)
{
	char	*z;

	IF_C(!pad,
		free(o->v);
		return (o->v = ft_strdup(""));)
	if (!(pad = MAX(pad - ft_strlen(o->v), 0)))
		return (o->v);
	z = ft_memset(ft_strnew(pad + 1), '0', pad);
	IF_C(o->p.flags & neg,
		z = ft_strjoin_free(ft_strdup("-"), z);
		((char*)o->v)[0] = '0';)
	return (ft_strjoin_free(z, o->v));
}

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
	size_t	len;

	len = 0;
	u[0] = (o->p.length & (l + ll) || ft_isuppercase(o->str[0]));
	u[1] = ft_tolower(o->str[0]) == 'u';
	o->v = ft_tolower(o->str[0]) == 'u' ?
		ft_itoa_unsigned(*(ull_t*)o->v) : ft_itoa(*(int64_t*)o->v);
	if (o->p.tick & 4)
		o->v = zero_i(o , o->p.precision);
	len = o->p.precision + o->p.width;
	IF_C(1, modify_o(o, "sign");)
	IF_C(1, modify_o(o, "pad");)
	append_o(o, o->v, len);
	return (len);
}

static void
	cast_i(va_list ap, ull_t *n, ull_t lm, int u)
{
	if (!lm)
		n[0] = va_arg(ap, int);
	else if (lm & hh)
		n[0] = (char)va_arg(ap, int);
	else if (lm & h)
		n[0] = (short)va_arg(ap, int);
	else if (lm & l)
		n[0] = (long)va_arg(ap, long);
	else if (lm & ll)
		n[0] = (long long)va_arg(ap, long long);
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
	o->p.flags |= (!U_VLS(o->str[0]) && num < 0) ? neg : 0;
	return (convert_i(o));
}
