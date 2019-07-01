/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _slen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:26:10 by viwade            #+#    #+#             */
/*   Updated: 2019/06/26 19:50:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t
	slen(const char *s)
{
	const char *e;

	e = s;
	while (*(e += !!e[0]))
		;
	return (e - s);
}

/*
**	SECURE STRLEN
*/

size_t
	slen_s(const char *s, size_t m)
{
	const char *e;

	e = s;
	while (*(e += !!e[0]) && m--)
		;
	return (e - s);
}
