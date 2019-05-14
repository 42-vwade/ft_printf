/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/14 01:40:36 by viwade           ###   ########.fr       */
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
	ft_putnbr((int)num);
	return (len + (num < 0));
}

static void
	put_uint(unsigned long long n)
{
	if (n >= 10)
		put_uint(n / 10);
	write(1, (char[1]){48 + n % 10}, 1);
}

int		parse_u(va_list args, t_format *o)
{
	int		num;
	size_t	len;

	num = (unsigned int)va_arg(args, int);
	len = ft_intlen(num);
	if (o->p.width && len < o->p.width)
		o->count += pad_i(ABS(o->p.width - len) - (num < 0), o->p.flags & 1, 0);
	put_uint((unsigned)num);
	return (len + (num < 0));
}
