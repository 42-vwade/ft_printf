/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 07:08:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	find_next(char *s)
{
	char	*e;

	e = s;
	while (e[0] != '%' && *(e += !!e[0]))
		;
	return (e - s);
}

void
	parse_input(t_format *obj, const char *fmt)
{
	size_t	i;

	while (*obj->str && !(i = 0))
	{
		i = find_next(obj->str);
		if (*obj->str != '%')
			obj->count += write(1, obj->str, i);
		if (obj->str[i] == '%' && obj->str[i + 1] == '%')
			obj->count += 2 * write(1, "%", 1);
		obj->str = (char *)&fmt[obj->count];
		if (*obj->str == '%')
			obj->count += get_params(obj, &obj->p);
	}
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
