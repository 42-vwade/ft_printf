/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/13 22:46:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		CHAR
*/

int		parse_c(va_list args, t_format *o)
{
	unsigned long int	c;

	if (ft_isuppercase(o->str[0]))
	{
		ft_putstr("LONG");
		c = (unsigned long int)va_arg(args, int);
		write(1, &c, sizeof(wchar_t));
	}
	else
	{
		c = (unsigned char)va_arg(args, int);
		write(1, &c, 1);
	}
	return (1);
}
