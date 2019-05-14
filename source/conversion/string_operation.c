/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/10 19:35:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

/*
**		STRING
*/

int		parse_s(va_list args, t_format *o)
{
	char	*s;
	size_t	len;

	s = (char *)va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	if (o->p.precision <= (len = ft_strlen(s)) && o->p.precision)
		return (write(1, s, len = o->p.precision));
	else
		return (write(1, s, len));
}
