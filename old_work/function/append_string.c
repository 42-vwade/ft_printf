/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:36 by viwade            #+#    #+#             */
/*   Updated: 2019/09/03 22:20:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	append_s(t_format *o)
{
	MATCH(o->z_pad, o->v = ft_append(o->v, o->z_pad, 0));
	MATCH(o->p.flags & zero, o->v = ft_append(o->v, o->pad, 0));
	ELSE(o->v = ft_append(o->v, o->pad, 0));
}
