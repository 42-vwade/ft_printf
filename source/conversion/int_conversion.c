/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:13:09 by viwade            #+#    #+#             */
/*   Updated: 2019/06/10 07:32:27 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
static FT_STR
	zero_i(t_format *o, ull_t pad)
{
	char	*z;

	IF_C(!pad,
		free(o->v);
		return (o->v = ft_strdup(""));)
	if (!(pad = MAX(pad - ft_strlen(o->v), 0)))
		return (o->v);
	z = ft_memset(ft_strnew(pad + 1), '0', pad);
	IF_C(o->p.flags & neg,
		z = ft_strjoin_free(ft_strdup("-"), z);
		((char*)o->v)[0] = '0';)
	return (ft_strjoin_free(z, o->v));
}

FT_STR
	pad_int(t_format *o, FT_STR s)
{
	IF_C(ft_strnequ(s, "precision", 9),
		o->v = zero_i(o, )
		);
}//*/
