/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/29 20:19:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define length_i_assign_type(t) ((t *)var)[0] = (t)va_arg(ap, t)
#define cast_uint(a) (o->str[0] == 'u' ? (uint32_t)(a) : (int32_t)(a))

/*
**		INT
*/

static void
	length_i(va_list ap, void *var, uint8_t length)
{

	if (!length)
		length_i_assign_type(int);
	else if (length & hh)
		((int64_t *)var)[0] = (char)va_arg(ap, int);
	else if (length & h)
		((int64_t *)var)[0] = (short)va_arg(ap, int);
	else if (length & l)
		length_i_assign_type(long);
	else if (length & ll)
		length_i_assign_type(long long);
}

static size_t
	write_uint(unsigned long long n, size_t len)
{
	size_t	l;

	if (!len)
		return (0);
	l = 0;
	if (n >= 10)
		l = write_uint(ABS(n / 10), --len);
	return (l + write(1, (char[1]){48 + ABS(n % 10)}, 1));
}

static int
	convert_i(void *data)
{
	size_t	len;
	t_format	*o;

	o = data;
	len = 0;
	if ((o->str[0] == 'i' || o->str[0] == 'd') &&
		((int)((int*)o->v)[0] >= 0 && o->p.flags & (plus + space)))
			len += write(1, o->p.flags & plus ? "+" : " ", 1) +
				write_uint((int)((int *)o->v)[0], o->p.precision);
	else if ((o->str[0] == 'i' || o->str[0] == 'd'))
		len += write_uint((int)((int *)o->v)[0], o->p.precision);
	else if (o->str[0] == 'u')
		len += prefix_o(o->p.flags) +
			write_uint((uint)((int *)o->v)[0], o->p.precision);
	else
		len += write_uint((uint)((int *)o->v)[0], o->p.precision);
	return (len);
}

static int
	sign_i(uint8_t *f, int64_t n)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += write(1, "-", 1);
	 if (f[0] & zero && !(f[0] & minus))
	 	f[0] &= ~zero;
	return (ret);
}

int
	parse_i(t_format *o)
{
	int64_t	num;
	size_t	len;
	size_t	ret;

	ret = 0;
	o->v = &num;
	length_i(o->arg, o->v, o->p.length);
	num = o->str[0] == 'u' ? (uint32_t)num : num;
	len = ft_intlen_base(num, 10);
	len = (num < 0 || o->p.flags & (space | plus)) + len;
	if (o->p.flags & zero && num < 0)
		ret += sign_i(&o->p.flags, num);
	ret += pad_o(&o->p.flags, MAX(o->p.width - len, 0));
	ret += convert_i(o);
	ret += pad_o(&o->p.flags, MAX(o->p.width - len, 0));
	return (len);
}
