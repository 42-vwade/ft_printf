/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 18:13:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define U_VLS(u) ((u)=='o'||(u)=='u'||(u)=='x')
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define VA_ASN(type)	va_arg(ap, type)
#define VA_I(t,a,u)	((u)?(unsigned t)va_arg(a,int):(signed t)va_arg(a,int))
#define VA_U(t,a,u)	((u)?(unsigned t)va_arg(a,t):(signed t)va_arg(a,t))
#define FI_C(c,v)	(c&(h)?(char)(*(char*)v):(int)*(int*)v)
#define FI_S(c,v)	(c&(h)?(short)(*(short*)v):FI_C(c,v))
#define FI_L(c,v)	(c&(l)?(long)(*(long*)v):FI_S(c,v))
#define FI_LL(c,v)	(c & (ll+j+z+t) ? (ll_t)(*(ll_t*)v) : FI_L(c,v) )
#define IT_F(u,f1,f2,p)	(u) ? f1(p) : f2(p)
#define CAST_C(c)	(c) &hh	? char : int
#define CAST_S(c)	(c) &h	? short : CAST_C(c,v)
#define CAST_L(c)	(c) &l	? long : CAST_S(c,v)
#define CAST_LL(c)	((c) & (ll+j+z+t) ? (ll_t) : CAST_L(c,v))
#define F3(l,v,f)	(f(ABS(*(char*)v)))
#define F2(l,v,f)	((l==2)?f(ABS(*(short*)v)):F3(l,v,f))
#define F1(l,v,f)	((l==4)?f(ABS(*(int*)v)):F2(l,v,f))
#define F0(l,v,f)	v=((l==8)?f(ABS(*(ll_t*)v)):F1(l,v,f))

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
	MATCH(neg & o->p.flags, F0(o->p.length, o->v, ft_itoa));
	ELSE(F0(o->p.length, o->v, ft_itoa_unsigned));
	precision_i(o);
	width_o(o);
	append_s(o);
	return (o->len);
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
	char	c;
	ull_t	num;

	o->v = &num;
	c = ft_tolower(o->str[0]);
	MATCH(ft_isuppercase(o->str[0]), o->p.length = ll);
	cast_o(o);
	MATCH(c != 'u' && num > (ull_t)0x80 << (o->p.length - 1) * 8,
		o->p.flags = o->p.flags & ~plus | 128);
	return (convert_i(o));
}
