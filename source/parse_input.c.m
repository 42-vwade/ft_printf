/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/09/06 02:22:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	find_next(const char *s)
{
	const char	*e;

	e = s;
	while (e[0] != '%' && *(e += !!e[0]))
		;
	return (e - s);
}

void
	parse_input(t_format *obj, const char *fmt)
{
	size_t	i;
	size_t	n;

	if ((i = !fmt))
		return (ft_error("error (ft_printf): A valid string was not entered."));
	while (fmt[i])
	{
		obj->str = (char *)&fmt[i];
		if (fmt[i] == '%')
			n = get_params(obj, 0);
		else if ((n = find_next(&fmt[i])))
			obj->v = ft_strsub(fmt, i, n);
		if (n)
			append_o(obj);
		i += n;
	}
	output_o(obj, obj->list);
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
