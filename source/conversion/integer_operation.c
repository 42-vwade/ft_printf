/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/04 03:18:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define LENGTH(t) {t}
#define CAST(ptr) *((int64_t*)(ptr))

/*
**		INT
*/

static int
	convert_i(t_format *o)
{
	char	u[2];
	size_t	ret;
	size_t	len;

	ret = 0;
	u[0] = (o->p.length & (l + ll) || ft_isuppercase(o->str[0]));
	u[1] = ft_tolower(o->str[0]) == 'u';
	o->v = u[1] ? ft_itoa_unsigned(*(ull_t*)o->v) : ft_itoa(*(int64_t*)o->v);
	len = ft_strlen(o->v);
	o->p.width = MAX((LL)(o->p.width - len), 0);
	if (o->p.flags & (plus + space + neg))
		modify_o(o, "sign");
	else
		modify_o(o, "pad");
	ret = write(1, o->v, ft_strlen(o->v));
	free(o->v);
	return (ret);
}

int
	parse_i(t_format *o)
{
	int64_t	num;

	o->v = &num;
	num = va_arg(o->arg, int64_t);
	o->p.flags |= (num < 0) << 7;
	length_o(o->v, o->p.length, o->str[0]);
	return (convert_i(o));
}
