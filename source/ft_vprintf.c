/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:39:52 by viwade            #+#    #+#             */
/*   Updated: 2019/06/06 04:50:42 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_vprintf(const char *format, va_list ap)
{
	t_format	o;

	ft_bzero(&o, sizeof(o));
	va_copy(o.ap, ap);
	parse_input(&o, o.str = (char *)format);
	va_end(o.ap);
	return (o.count);
}
