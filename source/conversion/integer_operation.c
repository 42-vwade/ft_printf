/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/03 10:18:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)
#define IS_SIGNED(l) (((l)=='u')? 0 : 1)
#define LENGTH(t) {t}

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
	o->v = u[1] ? ft_itoa_unsigned(*(uint64_t*)o->v) : ft_itoa(*(int64_t*)o->v);
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
	int64_t		num;
	uint64_t	unum;

	o->v = IS_SIGNED(ft_tolower(o->str[0])) ? (void*)&num : (void*)&unum;
	num = IS_SIGNED(o->str[0]) ? va_arg(o->arg, LL) : va_arg(o->arg, ULL);
	o->p.flags |= (num < 0) << 7;
	return (convert_i(o));
	num = ft_tolower(o->str[0]) == 'u' ? (uint32_t)num : num;
}
