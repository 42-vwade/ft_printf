/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 19:47:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PREF_X(t)

void
	width_o(t_format *o)
{
	ll_t	zpad;

	zpad = o->p.width - ft_strlen(o->v) - !!o->sign - ft_strlen(o->z_pad);
	hash_o(o);
	o->p.width = MAX((LL)zpad, 0);
	MATCH(!o->p.width, RET);
	o->pad =
	ft_memset(ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width);
	return ;
	if (o->p.flags & zero &&
			!((o->p.tick & 4) && ft_strchr("dioux", ft_tolower(*o->str))))
	{
		MATCH(ft_strchr("xp", ft_tolower(o->str[0])),
			o->v = search_and_splice(o->v, "0x", o->pad));
		ELSE(o->v = ft_append(o->pad, o->v, 3));
		return ;
	}
	ELSE(ft_memset(o->pad, ' ', o->p.width));
	if (minus & o->p.flags)
		o->v = ft_append(o->v, o->pad, 3);
	else
		o->v = ft_append(o->pad, o->v, 3);
	MATCH(ft_isuppercase(o->str[0]), ft_strcapitalize(o->v));
}
