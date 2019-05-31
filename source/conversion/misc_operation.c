/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:19:07 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 08:46:14 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define IF_STRNEQU(a, b, n) if (ft_strnequ((a), (b), (n))){

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

void
	modify_o(t_format *o, FT_STR s)
{
	IF_STRNEQU(s, "pad", 3)
		if (!o->p.width)
			return ;
		if (o->p.flags & minus)
			o->v = ft_strjoin_free(o->v, pad_o(o->p.flags, o->p.width));
		else
			o->v = ft_strjoin_free(pad_o(o->p.flags, o->p.width), o->v);
	}
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
		ft_memchr(pad, ' ', n);
	else
		ft_memchr(pad, flag & zero ? '0' : ' ', n);
	return (pad);
}
