/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 08:23:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_c(va_list args, t_format *o)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	write(1, &c, 1);
	o->count += 1;
	return (1);
}

int		parse_s(va_list args, t_format *o)
{
	char	*s;
	size_t  len;

	s = (char *)va_arg(args, char *);
	len = ft_strlen(s);
	if (!!o->p.precision && o->p.precision <= len)
		write(1, s, len = o->p.precision);
	else
		write(1, s, len);
	o->count += len;
	return (len);
}

int		parse_i(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_x(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_u(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_o(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_p(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_C(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_S(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_D(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_X(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}
