/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/04/29 17:25:42 by viwade           ###   ########.fr       */
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

	i = 0;
	obj->str = (char*)fmt;
	while (!(i = 0) && *obj->str)
	{
		if ((i = obj->str[0] == '%' && obj->str[1] == '%'))
			obj->count += write(1, "%", i++);
		else if (obj->str[0] == '%')
			i += get_params(obj, 0);
		else if (obj->str[0] != '%')
			obj->count += write(1, obj->str, i = find_next(obj->str));
		obj->str += i;
	}
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
