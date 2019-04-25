/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 08:18:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		OCTAL / HEX
*/

int		parse_o(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}

int		parse_hex(va_list args, t_format *o)
{
	int		num;

	num = (int)va_arg(args, int);
	if ((0))
		num = o->count;
	return (ft_intlen(num));
}
