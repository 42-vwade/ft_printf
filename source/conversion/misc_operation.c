/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:19:07 by viwade            #+#    #+#             */
/*   Updated: 2019/05/27 22:59:17 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int
	prefix_o(uint8_t flag)
{
	if (!(flag & 17))
		return (0);
	else if (flag & 1 << 0)
		return (write(1, "+", 1));
	else
		return (write(1, " ", 1));
}

/*
**	Takes a length <n> of the maximum # of spaces to pad.
**	Pad length = <n> width - <length> written
*/
int
	pad_o(t_format *o, int (*f)(), int64_t n)
{
	size_t	ret;

	ret = 0;
	if (!n)
		return(f(o));
	else if (o->p.flags & minus)
	{
		ret += f(o);
		while (MAX(o->p.width - ret, 0))
			ret += write(1, " ", 1);
		return (ret);
	}
	else
	{
		while (n--)
			ret += write(1, o->p.flags & zero ? "0" : " ", 1);
		ret += f(o);
		return (ret);
	}
}
