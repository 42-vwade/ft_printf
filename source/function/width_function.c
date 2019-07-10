/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/09 18:58:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PREF_X(t)

void
	width_o(t_format *o)
{
	char	*pad;

	hash_o(o);
	if (!(o->p.width = MAX((LL)(o->p.width - ft_strlen(o->v)), 0)))
		return ;
	o->len += o->p.width;
	pad = ft_memset(
		ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width);
	if (o->p.flags & zero &&
			!((o->p.tick & 4) && ft_strchr("dioux", ft_tolower(*o->str))))
	{
		IF_E(ft_strchr("xp", ft_tolower(o->str[0])),
			o->v = search_and_splice(o->v, "0x", pad),
			o->v = ft_strjoin_free(pad, o->v));
		return ;
	}
	else
		ft_memset(pad, ' ', o->p.width);
	if (minus & o->p.flags)
		o->v = ft_strjoin_free(o->v, pad);
	else
		o->v = ft_strjoin_free(pad, o->v);
	IF_C(ft_isuppercase(o->str[0]), ft_strcapitalize(o->v));
}
