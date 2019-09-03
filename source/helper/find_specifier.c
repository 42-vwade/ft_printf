/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:35 by viwade            #+#    #+#             */
/*   Updated: 2019/09/02 19:18:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

size_t	find_specifier(const char *format)
{
	size_t	n;

	n = 1;
	if (format[0] != '%')
		ft_error("invalid syntax");
	while (format[n] && !ft_strchr(SPECIFIER_LIST, ft_tolower(format[n])))
		;
}
