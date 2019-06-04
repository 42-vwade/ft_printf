/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:19:07 by viwade            #+#    #+#             */
/*   Updated: 2019/06/04 06:39:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define IF_STRNEQU(a, b, n, t) if (ft_strnequ((a),(b),(n))){t}
#define A_M(a, b) ((a) & (b))
#define B_M(a, b) (!((a) & (b)))
#define C_M(a,b,c) (A_M(a,b) && B_M(a,c))
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'
#define	I_VLS(u) ((u)&&((u)=='i'||(u)=='d'))
#define	U_VLS(u) ((u)&&((u)=='o'||(u)=='u'||(u)=='x'))
#define	N_VLS(u) ((u)&&((u)=='n'))
#define	F_VLS(u) ((u)&&((u)=='e'||(u)=='f'||(u)=='g'))
#define	C_VLS(u) ((u)&&((u)=='c'))
#define	S_VLS(u) ((u)&&((u)=='s'))
#define APPLY_L(value, type) value = (type)value; return;
#define IF_E(c,a,b)	{if(c){a}else{b}}
#define I_0(n)		if(n){APPLY_L(n, int);ft_putstr("ii");return;}
#define I_1(f,n)	if(f & hh){APPLY_L(n, char);ft_putstr("ihh");}
#define I_2(f,n)	if(f & h){APPLY_L(n, short);ft_putstr("ih");}
#define I_4(f,n)	if(f & l){APPLY_L(n, long);ft_putstr("il");}
#define I_8(f,n)	if(f & ll){APPLY_L(n, long long);ft_putstr("ill");}
#define I_J(f,n)	if(f & j){APPLY_L(n, intmax_t);ft_putstr("ij");}
#define I_T(f,n)	if(f & t){APPLY_L(n, ssize_t);ft_putstr("it");}
#define I_Z(f,n)	if(f & z){APPLY_L(n, ssize_t);ft_putstr("iz");}
#define U_0(n)		if(n){APPLY_L(n, unsigned);ft_putstr("uu");return;}
#define U_1(f,n)	if(f & hh){APPLY_L(n, unsigned char);ft_putstr("uhh");}
#define U_2(f,n)	if(f & h){APPLY_L(n, unsigned short);ft_putstr("uh");}
#define U_4(f,n)	if(f & l){APPLY_L(n, unsigned long);ft_putstr("ul");}
#define U_8(f,n)	if(f & ll){APPLY_L(n, unsigned long long);ft_putstr("ull");}
#define U_J(f,n)	if(f & j){APPLY_L(n, uintmax_t);ft_putstr("uj");}
#define U_T(f,n)	if(f & t){APPLY_L(n, size_t);ft_putstr("ut");}
#define U_Z(f,n)	if(f & z){APPLY_L(n, size_t);ft_putstr("uz");}
#define F_0(n)		if(n){APPLY_L(n, double);ft_putstr("fd");return;}
#define F_1(f,n)	if(f & LD){APPLY_L(n, long double);ft_putstr("Ld");}
#define I_LENGTH(a, n, t) if(I_VLS(a)){t;return;}else{I_0(n);}
#define U_LENGTH(a, n, t) if(U_VLS(a)){t;return;}else{U_0(n);}
#define F_LENGTH(a, n, t) if(F_VLS(a)){t;return;}else{F_0(n);}

FT_VOID
	length_o(ull_t *num, ull_t lm, char c)
{
	c = 'u' * U_VLS(c) || 'f' * F_VLS(c);
	if (lm & hh)
		IF_E(c, APPLY_L(num[0], unsigned char), APPLY_L(num[0], char))
	if (lm & h)
		IF_E(c, APPLY_L(num[0], unsigned short), APPLY_L(num[0], short))
	if (lm & l)
		IF_E(c, APPLY_L(num[0], unsigned long), APPLY_L(num[0], long))
	if (lm & ll)
		IF_E(c, APPLY_L(num[0], ull_t), APPLY_L(num[0], ll_t))
	if (lm & j)
		IF_E(c, APPLY_L(num[0], uintmax_t), APPLY_L(num[0], intmax_t))
	if (lm & z || lm & t)
		IF_E(c, APPLY_L(num[0], size_t), APPLY_L(num[0], ssize_t))
	if (lm & LD)
		IF_E(c == 'f', APPLY_L(num[0], ld_t), APPLY_L(num[0], double))
}

/*
**	Takes a length <n> of the maximum # of spaces to pad.
**	Pad length = <n> width - <length> written
*/
FT_STR
	pad_o(uint8_t flag, FT_SIZE n)
{
	FT_STR	pad;

	pad = ft_strnew(n + 1);
	if (flag & minus)
		ft_memset(pad, ' ', n);
	else
		ft_memset(pad, flag & zero ? '0' : ' ', n);
	return (pad);
}

static FT_STR
	sign_o(uint8_t flag, FT_STR nbr, FT_STR pad)
{
	char	*sign;

	if (hash & flag)
	sign = (char[2]){SIGN_M(flag, plus, space, neg), 0};
	if (!pad && !(flag & neg))
		return (ft_strjoin_free(ft_strdup(sign), nbr));
	if (pad && flag & zero && !(minus & flag))
	{
		pad[0] = sign[0];
		if (neg & flag)
			nbr[0] = '0';
		return (ft_strjoin_free(pad, nbr));
	}
	return (nbr);
}

void
	modify_o(t_format *o, FT_STR s)
{
	IF_STRNEQU(s, "pad", 3,
		if (!o->p.width)
			return ;
		if (o->p.flags & minus)
			o->v = ft_strjoin_free(o->v, pad_o(o->p.flags, o->p.width));
		else
			o->v = ft_strjoin_free(&pad_o(o->p.flags, o->p.width)[0], o->v);)
	IF_STRNEQU(s, "sign", 4,
		if (!o->p.width)
			o->v = sign_o(o->p.flags, o->v, NULL);
		else
			o->v = sign_o(o->p.flags, o->v, pad_o(o->p.flags, o->p.width));)
	IF_STRNEQU(s, "hex", 3,
		if (hash & o->p.flags || ft_tolower(o->str[0]) == 'p')
			o->v = ft_strjoin_free(ft_strdup("0x"), o->v);
	)
	IF_STRNEQU(s, "octal", 5,
		if (hash & o->p.flags && !(neg & o->p.flags))
			o->v = ft_strjoin_free(ft_strdup("0"), o->v);
	)
}
