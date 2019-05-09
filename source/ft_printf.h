/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:19 by viwade            #+#    #+#             */
/*   Updated: 2019/05/09 07:37:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <math.h>
# include "../libft/assets/libft_core/libft.h"
# include "ft_printf_structs.h"

/*
**	--	REQUIREMENTS	--
**	CONVERSIONS
**		csp / diouxX / f
**	<<		BONUS		>>
**	CONVERSIONS --	REMAINING
**		FeEgGaAn%		<<	diuoxXfFeEgGaAcspn%
*/

int		ft_printf(const char *format, ...);
void	parse_input(t_format *object, const char *format);
int		get_params(t_format *obj, size_t i);

size_t	ftprintf_write(char *s, size_t len, t_format *o);

int		parse_c(va_list args, t_format *o);
int		parse_s(va_list args, t_format *o);
int		parse_i(va_list args, t_format *o);
int		parse_u(va_list args, t_format *o);
int		parse_o(va_list args, t_format *o);
int		parse_hex(va_list args, t_format *o);
int		parse_f(va_list args, t_format *o);

#endif
