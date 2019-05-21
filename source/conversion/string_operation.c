/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/21 07:40:43 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

/*
**		STRING
*/

static int
	write_lstr(uint32_t *s, size_t n)
{
	size_t	len;

	if (n && n < ft_lstrlen(s))
		len = print_utf8_n(s, n);
	else
		len = print_utf8(s);
	return (len);
}

static int
	write_str(char *s, size_t n)
{
	size_t	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (n && n < len)
		return (write(1, s, n));
	else
		return (write(1, s, len));
}

int
	parse_s(va_list args, t_format *o)
{
	if (ft_isuppercase(o->str[0]))
		return (write_lstr((int*)va_arg(args, int *), o->p.precision));
	else
		return (write_str((char*)va_arg(args, char*), o->p.precision));
}
