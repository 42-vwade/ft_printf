/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:45:55 by viwade            #+#    #+#             */
/*   Updated: 2019/09/09 01:31:07 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	hash_o(t_format *o)
{
	char	c;
	char	nz;

	MATCH(!(hash & o->p.flags), RET);
	c = ft_tolower(o->str[0]);
	nz = !!ft_atoi(o->v);
	if (ft_cmp(c, 'o') && (nz || (nz && !(o->p.tick & 4 && !o->p.precision))))
		o->prefix = "0";
	else if ((ft_cmp('x', c) && nz) || ft_cmp('p', c))
		o->prefix = "0x";
	else if (ft_strchr("aefg", c) && !ft_strchr(o->v, '.'))
		o->v = ft_append(o->v, ".", 1);
	if (ft_cmp(c, 'g'))
		;
}
