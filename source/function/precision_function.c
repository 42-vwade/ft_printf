/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:05:10 by viwade            #+#    #+#             */
/*   Updated: 2019/06/08 01:23:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	Ensure o->v is allocated before use.
*/

/*
**	Creates a zero-padded number.
**	If the number is negative, the sign is shifted to the left of all zeros.
**	If padding length is zero, no modifications to value are made.
**	If no precision is given, no modifications are made.
*/

void	precision_i(t_format *o)
{
	char	*z;
	char	*t;
	size_t	len;

	precision_o(o);
	if (!(o->p.tick & 4))
		return ;
	len = MAX(o->p.precision - ft_strlen(o->v), 0);
	if (!len)
		return ;
	z = ft_memset(ft_strnew(len), '0', len);
	if (neg & o->p.flags && (t = ft_strchr(o->v, '-')))
	{
		t[0] = '0';
		z[0] = '-';
	}
	o->v = ft_strjoin_free(z, o->v);
}

void	precision_s(t_format *o)
{
	char	u;

	if ((u = o->p.length & (l + ll) || ft_isuppercase(o->str[0])))
		o->len = o->p.tick & 4 ? MIN(
			ft_lstrlen(o->v), o->p.precision) : ft_lstrlen(o->v);
	else
		o->len = ft_strlen(o->v);

	o->v = u ? encode_utf8(str_utf8(o->v, o->len)) : ft_strdup(o->v);
}

size_t	precision_o(t_format *o)
{
	if (o->p.tick & 4)
		o->p.precision = MIN(ft_strlen(o->v), o->p.precision);
	else
		o->p.precision = ft_strlen(o->v);
	return (o->p.precision);
}
