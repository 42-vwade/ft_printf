/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:19 by viwade            #+#    #+#             */
/*   Updated: 2019/08/05 23:22:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "ft_printf_structs.h"

/*
**	--	REQUIREMENTS	--00
**			CONVERSIONS
**				csp / diouxX / f
**	<<	BONUS	>>
**			CONVERSIONS --	REMAINING
**				FeEgGaAn%		<<	diuoxXfFeEgGaAcspn%
*/

/*
**		EPIDERMIC SUBSURFACE SCATTERING
*/

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);

/*
**		SUBDERMAL FUNCTIONS
*/

void	parse_input(t_format *object, const char *format);
int		get_params(t_format *obj, size_t i);

size_t	ftprintf_write(char *s, size_t len, t_format *o);

int		parse_c(t_format *o);
int		parse_s(t_format *o);
int		parse_i(t_format *o);
int		parse_u(t_format *o);
int		parse_x(t_format *o);
int		parse_f(t_format *o);

void	append_o(t_format *o);
char	*graft_o(t_list *start);
void	output_o(t_format *o, t_list *node);
void	cast_o(t_format *o);
size_t	precision_o(t_format *o);
void	precision_s(t_format *o);
void	precision_i(t_format *o);
void	precision_f(t_format *o);
void	width_o(t_format *o);
FT_STR	hash_o(t_format *o);
FT_STR	pad_o(t_format *o);
FT_VOID	modify_o(t_format *o, FT_STR s);

#endif
