/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:03 by viwade            #+#    #+#             */
/*   Updated: 2019/08/05 23:22:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	length;

	length = 0;
	va_start(ap, format);
	length = ft_vprintf(format, ap);
	va_end(ap);
	return (length);
}
