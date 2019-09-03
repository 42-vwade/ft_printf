/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:35 by viwade            #+#    #+#             */
/*   Updated: 2019/09/03 00:50:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

size_t	find_specifier(t_format *o, const char *format)
{
	size_t	n;

	n = 1;
	if (format[0] && format[0] != '%')
		ft_error("invalid syntax");
	if (format[0] && !format[1])
		return (0);
	while (format[n] && !ft_strchr(SPECIFIER_LIST, ft_tolower(format[n])))
		++n;
	if (ft_strchr(SPECIFIER_LIST, ft_tolower(format[n])))
		return (n - 1);
	else
		return (0);
}
