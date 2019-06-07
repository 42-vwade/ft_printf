/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/06 04:53:13 by viwade           ###   ########.fr       */
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

static void
	length_x(FT_ULL *num, ULL lm)
{
	FT_ULL	n;

	n = num[0];
	U_LENGTH(lm, n,
		if (lm & hh)
			U_HH(n);
		else if (lm && h)
			U_H(n);
		else if (lm && l)
			U_L(n);
		else if (lm && ll)
			U_LL(n);
		else
			n = (unsigned)n;
	)
	num[0] = n;
}

static FT_SIZE
	convert_x(t_format *o)
{
	char	u;
	size_t	ret;
	size_t	len;

	ret = 0;
	u = ft_tolower(o->str[0]) == 'o';
	o->v = ft_itoa_base(*(FT_ULL*)o->v, u ? 8 : 16);
	IF_C(ft_isuppercase(o->str[0]), ft_strcapitalize(o->v);)
	len = ft_strlen(o->v);
	o->p.width = MAX((LL)(o->p.width - len), 0);
	modify_o(o, "pad");
	modify_o(o, u ? "octal" : "hex");
	ret = write(1, o->v, ft_strlen(o->v));
	free(o->v);
	return (ret);
}

int		parse_x(t_format *o)
{

	FT_ULL	num;

	if (o->str[0] == 'p' || o->str[0] == 'P')
		num = va_arg(o->ap, intptr_t);
	else
		num = va_arg(o->ap, FT_ULL);
	o->p.flags &= !num && o->p.tick & 4 ? o->p.flags | neg : ~(char)neg;
	o->v = &num;
	length_x(o->v, o->p.length);
	return (convert_x(o));
}
