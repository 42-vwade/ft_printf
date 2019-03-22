/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:40 by viwade            #+#    #+#             */
/*   Updated: 2019/03/22 12:20:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef t_context	t_ctx_t;

char
	*resolve_arg(t_format *obj, const char *fmt)
{
	char	*output;
	t_ctx_t	context;
	t_param	set;

	if (get_params(fmt, &set) == -1)
		return (NULL);
	context = get_context(&set);
	output = ft_strdup("resolve_arg function called\n");
	return (obj->str);
}

/*
**	//	Context will generate the output string.
**	Will be appended to the output string upon returning.
**		If the parameters given are invalid, NULL is returned.
**		A check should be made in the main printf body for this NULL.
*/
