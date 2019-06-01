/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:19:07 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 21:56:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define IF_STRNEQU(a, b, n, t) if (ft_strnequ((a),(b),(n))){t}
#define A_M(a, b) ((a) & (b))
#define B_M(a, b) (!((a) & (b)))
#define C_M(a,b,c) (A_M(a,b) && B_M(a,c))
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'

int
	prefix_o(uint8_t flag)
{
	if (!(flag & 17))
		return (0);
	else if (flag & 1 << 0)
		return (write(1, "+", 1));
	else
		return (write(1, " ", 1));
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
	if (flag & (neg + zero))
		pad[0] = '-';
	return (pad);
}

static FT_STR
	sign_o(uint8_t flag, FT_STR nbr, FT_STR pad)
{
	char	*sign;

	sign = (char[2]){SIGN_M(flag, plus, space, neg), 0};
	if (!pad && !(flag & neg))
		return (ft_strjoin_free(ft_strdup(sign), nbr));
	if (pad && flag & (neg + zero) && !(minus & flag))
	{
		pad[0] = sign[0];
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
}
