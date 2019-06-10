/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2019/06/10 00:42:59 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	width_o(t_format *o)
{
	char	*pad;

	if (!(o->p.width = MAX((LL)(o->p.width - ft_strlen(o->v)), 0)))
		return ;
	pad = ft_strnew(o->p.width);
	if (o->p.flags & zero && !(o->p.flags & minus) &&
			!(o->p.tick & 4 && ft_strchr("dioux", ft_tolower(*o->str))))
	{
		ft_memset(pad, '0', o->p.width);
		if ((neg + plus + space) & o->p.flags)
		{
			pad[0] = ((char*)o->v)[0];
			((char*)o->v)[0] = '0';
		}
	}
	else
		ft_memset(pad, ' ', o->p.width);
	if (minus & o->p.flags)
		o->v = ft_strjoin_free(o->v, pad);
	else
		o->v = ft_strjoin_free(pad, o->v);
	if (ft_isuppercase(o->str[0]))
		ft_strcapitalize(o->v);
}
