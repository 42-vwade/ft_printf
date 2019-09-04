/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:45:55 by viwade            #+#    #+#             */
/*   Updated: 2019/09/03 22:00:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	hash_o(t_format *o)
{
	char	c;
	char	nz;

	if (!(hash & o->p.flags))
		return ;
	c = ft_tolower(o->str[0]);
	nz = !!ft_atoi(o->v);
	if (ft_cmp(c, 'o') && !(!nz && (o->p.tick & 4 && !o->p.precision)))
		o->v = ft_append("0", o->v, 2);
	else if (ft_cmp(c, 'x') && nz)
		o->v = ft_append("0x", o->v, 2);
	else if (ft_strchr("aefg", c) && !ft_strchr(o->v, '.'))
		o->v = ft_append(o->v, ".", 1);
	if (ft_cmp(c, 'g'))
		;
}
