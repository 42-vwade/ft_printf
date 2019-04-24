/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:03 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 06:50:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(const char *format, ...)
{
	t_format	obj;

	obj.str = (char *)format;
	va_start(obj.arg, format);
	parse_input(&obj);
	va_end(obj.arg);
	return (obj.count);
}
