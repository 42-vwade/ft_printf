/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 07:32:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	find_next(char *s)
{
	char	*e;

	e = s;
	while (*(e += !!e[0] && e[0] != '%'))
		;
	return (e - s);
}

void	parse_input(t_format *obj)
{
	size_t	i;

	while (*obj->str && !(i = 0))
	{
		i = find_next(obj->str);
		if (*obj->str != '%')
			obj->count += write(1, obj->str, i);
		if (obj->str[i] == '%' && obj->str[i + 1] == '%')
			obj->count += 2 * write(1, "%", 1);
		obj->count += get_params(obj, &obj->p);
		obj->str += obj->count;
	}
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
