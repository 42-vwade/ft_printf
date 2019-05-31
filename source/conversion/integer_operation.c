/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 12:29:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define length_i_assign_type(t) ((t *)var)[0] = (t)va_arg(ap, t)
#define cast_uint(a) (o->str[0] == 'u' ? (uint32_t)(a) : (int32_t)(a))
#define TYPE (ft_tolower(o->str[0]) == 'u') ? (uint64_t *) : (int64_t *)

/*
**		INT
*/

static void
	length_i(va_list ap, int64_t *var, uint8_t length)
{

	if (!length)
		length_i_assign_type(int);
	else if (length & hh)
		((int64_t *)var)[0] = (char)va_arg(ap, int);
	else if (length & h)
		((int64_t *)var)[0] = (short)va_arg(ap, int);
	else if (length & l)
		length_i_assign_type(long);
	else if (length & ll)
		length_i_assign_type(long long);
}

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
	modify_o(o, "pad");
	ret = write(1, o->v, len);
	free(o->v);
	return (ret);
}

int
	parse_i(t_format *o)
{
	int64_t	num;

	o->v = &num;
	length_i(o->arg, o->v, o->p.length);
	return (convert_i(o));
	num = ft_tolower(o->str[0]) == 'u' ? (uint32_t)num : num;
}
