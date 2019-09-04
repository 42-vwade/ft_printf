/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:49:18 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 01:14:22 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static void
	search_flags(ull_t *set, const char *f, size_t *len, size_t *i)
{
	while (*i < *len || (*i = 0))
	{
		MATCH(f[*i] == '+', set[0] = (set[0] | plus) & ~(space));
		OR(f[*i] == '-', set[0] = (set[0] | minus) & ~(zero));
		OR(f[*i] == '0', set[0] |= !(minus & set[0]) << 2);
		OR(f[*i] == '#', set[0] |= 1 << 3);
		OR(f[*i] == ' ', set[0] |= !(plus & set[0]) << 4);
		ELSE(*i = *i + 1);
	}
}

void
	search_parameters(t_format *o, const char *format)
{
	size_t	i;

	i = 0;
	search_flags(&o->p.flags, format, &o->len, &i);
}
