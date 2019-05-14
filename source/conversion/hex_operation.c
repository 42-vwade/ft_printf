/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/14 08:19:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PLUS(n) ((n) & (1 << 0))
#define MINUS(n) ((n) & (1 << 1))
#define ZERO(n) ((n) & (1 << 2))
#define HASH(n) ((n) & (1 << 3))
#define SPACE(n) ((n) & (1 << 4))

/*
**		OCTAL / HEX
*/

int		parse_o(va_list args, t_format *o)
{
	unsigned int		num;
	char	*str;

	num = (unsigned)va_arg(args, int);
	if (ft_isuppercase(o->str[0]))
		ft_strcapitalize(str = ft_itoa_base(num, 8));
	else
		str = ft_itoa_base(num, 8);
	if (HASH(o->p.flags))
		str = ft_strjoin_free(ft_strdup("0"), str);
	num = write(1, str, ft_strlen(str));
	free(str);
	return (num);
}

int		parse_hex(va_list args, t_format *o)
{
	long long	num;
	intptr_t	ptr;
	char	*str;

	if (o->str[0] == 'p' || o->str[0] == 'P')
		num = (intptr_t)va_arg(args, intptr_t);
	else
		num = (int)va_arg(args, int);
	str = ft_strjoin_free(ft_strdup("0x"), ft_itoa_base(num, 16));
	if (ft_isuppercase(o->str[0]))
		ft_strcapitalize(str);
	num = write(1, str, ft_strlen(str));
	free(str);
	return (num);
}
