/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:35 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 00:47:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

size_t	find_specifier(t_format *o, const char *format)
{
	size_t	n;

	MATCH(format[0] && format[0] != '%', ft_error("invalid syntax"));
	MATCH(format[0] && !format[1], RET(0));
	n = 1;
	while (format[n] && !o->jump[ft_tolower(format[n])])
		++n;
	MATCH(o->jump[ft_tolower(format[n])], RET(n - 1));
	ELSE(RET(0));
}
