/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/06/26 19:13:15 by viwade           ###   ########.fr       */
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
	char	output[4194304];

	if ((i = !fmt))
		return (ft_error("error (ft_printf): A valid string was not entered."));
	output[0] = 0;
	obj->out = &output[0];
	while (fmt[i])
	{
		obj->free = 0;
		obj->str = (char *)&fmt[i];
		if (fmt[i] == '%')
			n = get_params(obj, 0);
		else if ((n = find_next(&fmt[i])))
			obj->v = ft_strsub(fmt, i, n);
		if (n)
			append_o(obj);
		i += n;
	}
	output_o(obj);
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
