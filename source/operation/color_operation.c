/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:57:50 by viwade            #+#    #+#             */
/*   Updated: 2019/09/10 01:19:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define C_RESET		0
#define C_BLACK		0
#define C_RED		1
#define C_GREEN		2
#define C_YELLOW	3
#define C_BLUE		4
#define C_MAGENTA	5
#define C_CYAN		6
#define C_WHITE		7
#define C_B_BLACK	8
#define C_B_RED		9
#define C_B_GREEN	10
#define C_B_YELLOW	11
#define C_B_BLUE	12
#define C_B_MAGENTA	13
#define C_B_CYAN	14
#define C_B_WHITE	15

Black: \u001b[30m
Red: \u001b[31m
Green: \u001b[32m
Yellow: \u001b[33m
Blue: \u001b[34m
Magenta: \u001b[35m
Cyan: \u001b[36m
White: \u001b[37m
Reset: \u001b[0m
#define	COLOR_GET()

static ull_t
	synthesize_color(char *s)
{
	char	bright;
	char	*w;
	char	*tmp;

	MATCH(!s, RET(0));
	bright = 0;
	MATCH(!(s = ft_strtrim(s)), ft_error("problem with trimmed string."));
	ft_strtolower(&s);
	tmp = s;
	MATCH(bright = 8 * ft_strnequ("bright", s, 6), ((s += 6) || 1)
		&& (s = ft_strtrim(s)));
	ft_memdel((void**)&tmp);

}

int	parse_a(t_format *o)
{
	ull_t	color;

	o->v = &color;
	MATCH(o->p.flags & hash, color = va_arg(o->ap, int));
	ELSE(o->v = va_arg(o->ap, void *));
	MATCH(o->v != &color, ((color = synthesize_color(o->v)) || 1)
		&& (o->v = &color));
		color, 16
}
