/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:19 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 08:29:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "../libft/libft.h"
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
int32_t	get_params(t_format *object, t_param *param_addr);

int		parse_c(va_list args, t_format *o);
int		parse_s(va_list args, t_format *o);
int		parse_i(va_list args, t_format *o);
int		parse_u(va_list args, t_format *o);
int		parse_o(va_list args, t_format *o);
int		parse_hex(va_list args, t_format *o);
int		parse_f(va_list args, t_format *o);

#endif
