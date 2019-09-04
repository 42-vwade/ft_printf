/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2019/09/03 22:12:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PREF_X(t)

void
	width_o(t_format *o)
{
	hash_o(o);
	o->p.width = MAX((LL)(o->p.width - ft_strlen(o->v)), 0);
	MATCH(!o->p.width, RET);
	o->pad =
	ft_memset(ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width);
	return ;
	if (o->p.flags & zero &&
			!((o->p.tick & 4) && ft_strchr("dioux", ft_tolower(*o->str))))
	{
		MATCH(ft_strchr("xp", ft_tolower(o->str[0])),
			o->v = search_and_splice(o->v, "0x", o->pad));
		ELSE(o->v = ft_append(o->pad, o->v, 0));
		return ;
	}
	ELSE(ft_memset(o->pad, ' ', o->p.width));
	if (minus & o->p.flags)
		o->v = ft_append(o->v, o->pad, 0);
	else
		o->v = ft_append(o->pad, o->v, 0);
	(ft_isuppercase(o->str[0]), ft_strcapitalize(o->v));
}
