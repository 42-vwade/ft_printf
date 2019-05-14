/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/14 00:32:17 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		INT
*/

static int
	pad_i(size_t len, char plus, size_t i)
{
	while (len - i++)
		write(1, (plus && i == 1) ? "+" : "0", 1);
	return (len);
}

int		parse_i(va_list args, t_format *o)
{
	int		num;
	size_t	len;

	num = (int)va_arg(args, int);
	len = ft_intlen(num);
	if (o->p.width && len < o->p.width)
		o->count += pad_i(ABS(o->p.width - len) - (num < 0), o->p.flags & 1, 0);
	ft_putnbr(num);
	return (len + (num < 0));
}

int		parse_u(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}
