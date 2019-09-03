/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:45:55 by viwade            #+#    #+#             */
/*   Updated: 2019/08/02 12:16:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	Correlates hash flag
**	If no hash flag, return
**	If operation is 'octal' and value is not nonzero, and precision is given,
**		Prepend '0' to beginning of string;
**	If operation is 'hexadecimal' and value is nonzero,
**		Prepend '0x' to beginning of string;
**	If operation is 'float' and value does not contain a decimal value,
**		Append a '.' decimal character to end of string;
**	If operation is 'g' (float)
**		Do something;
*/

char
	*hash_o(t_format *o)
{
	char	c;
	char	nz;

	if ((c = ft_tolower(*o->str)) && !(hash & o->p.flags))
		return (NULL);
	nz = !!ft_atoi(o->v);
	if ((c == 'd' || c == 'i' || c == 'u') && (neg + plus) & o->p.flags)
		o->v = ft_strjoin_free(ft_strdup(plus & o->p.flags ? "+" : ""), o->v);
	if (ft_cmp(c, 'o') && !(!nz && (o->p.tick & 4 && !o->p.precision)))
		return (ft_strdup("0"));
	else if (ft_cmp(c, 'x') && nz)
		return (ft_strdup("0x"));
	else if (ft_strchr("aefg", c) && !ft_strchr(o->v, '.'))
		o->v = ft_strjoin_free(o->v, ft_strdup("."));
	if (ft_cmp(c, 'g'))
		;
	return (NULL);
}

/*
**	char
**		*hash_o(t_format *o)
**	{
**		char	c;
**		char	nz;
**			o->p.flags &= ~(plus * (plus & o->p.flags && (neg & ~o->p.flags)));
**		if (!(hash & o->p.flags))
**			return (0);
**		c = ft_tolower(o->str[0]);
**		nz = !!ft_atoi(o->v);
**		if (ft_cmp(c, 'o') && !(!nz && (o->p.tick & 4 && !o->p.precision)))
**			o->v = ft_strjoin_free(ft_strdup("0"), o->v);
**		else if (ft_cmp(c, 'x') && nz)
**			o->v = ft_strjoin_free(ft_strdup("0x"), o->v);
**		else if (ft_strchr("aefg", c) && !ft_strchr(o->v, '.'))
**			o->v = ft_strjoin_free(o->v, ft_strdup("."));
**		if (ft_cmp(c, 'g'))
**			;
**	}
*/
