/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 11:58:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		STRING
*/

int		parse_s(va_list args, t_format *o)
{
	char	*s;
	size_t	len;

	s = (char *)va_arg(args, char *);
	len = ft_strlen(s);
	if (!!o->p.precision && o->p.precision <= len)
		o->count += write(1, s, len = o->p.precision);
	else
		o->count += write(1, s, len);
	return (len);
}
