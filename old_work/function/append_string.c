/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:36 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 00:25:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	append_s(t_format *o)
{
	char	*tmp;

	tmp = 0;
	MATCH(o->sign && o->z_pad, o->z_pad = ft_append(o->sign, o->z_pad, 2));
	OR(o->sign, o->v = ft_append(o->sign, o->v, 2));
	MATCH(o->z_pad, o->v = ft_append(o->v, o->z_pad, 3));
	MATCH(o->p.flags & minus, o->v = ft_append(o->v, o->pad, 3));
	ELSE(o->v = ft_append(o->v, o->pad, 3));
	MATCH(ANY2(o->str[0], 'X', 'P'), ft_strcapitalize(o->v));
	append_o(o);
}
