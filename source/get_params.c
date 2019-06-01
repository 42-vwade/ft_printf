/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/06/01 07:01:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "global.h"

typedef t_param	t_context_t;

static int
	set_flags(uint8_t *set, const char *s, uint i)
{
	set[0] = 0;
	while (s[i++])
		if (s[i - 1] == '+')
			set[0] |= 1 << 0;
		else if (s[i - 1] == '-')
			set[0] |= 1 << 1;
		else if (s[i - 1] == '0')
			set[0] |= 1 << 2;
		else if (s[i - 1] == '#')
			set[0] |= 1 << 3;
		else if (s[i - 1] == ' ')
			set[0] |= 1 << 4;
		else
			return (i - 1);
	return (i);
}

static int
	set_width(uint64_t *w, uint64_t *p, const char *s, t_format *o)
{
	uint	i;
	char	move;

	i = 0;
	if (s[i] == '*')
		w[0] = (int)va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		w[0] = ft_atoi(&s[i]);
	if ((o->p.tick |= !!w[0] << 1) & 1 << 1)
		i += (s[i] == '*') ? 1 : ft_intlen(w[0]);
	if (s[i++] != '.')
		return (i - 1);
	o->p.tick |= 1 << 2;
	if ((move = s[i] == '*'))
		p[0] = (int)va_arg(o->arg, int);
	else if ((move = 2 * ft_isdigit(s[i])))
		p[0] = ft_atoi(&s[i]);
	//p[0] = !(INT_MAX & p[0]) ? 1 : p[0];
	if (move)
		i += (s[i] == '*') ? 1 : ft_intlen(p[0]);
	return (i);
}

/*
**	Returns zero if length parameter is not modified.
**	Otherwise, a length is determined, returned, and a specific flag is set.
*/
static int
	set_length(uint8_t *l, const char *s, uint i)
{
	l[0] = 0;
	if (s[i] == 'h')
		l[0] |= (s[i + 1] == 'h') ? hh : h;
	else if (ft_tolower(s[i]) == 'l')
		l[0] |= (ft_tolower(s[i + 1]) == 'l') ? ll : 1 << 2;
	else if (s[i] == 'j')
		l[0] |= j;
	else if (s[i] == 'z')
		l[0] |= z;
	if (l[0])
		i += (s[i + 1] == 'h' || s[i + 1] == 'l') ? 2 : 1;
	return (i);
}

/*
**	TODO	-->	ADD VALIDATOR to select_function
*/

static void
	select_function(t_format *o, char c, uint i)
{
	o->p.tick |= ft_isuppercase(c) << 4;
	while (g_dispatch[i++].type)
		if (g_dispatch[i - 1].type == c)
		{
			o->count += g_dispatch[i - 1].f(o);
			break ;
		}
		else if (!g_dispatch[i].type)
			ft_error("ft_printf: No valid parameter found. Exiting.");
}

int
	get_params(t_format *obj, size_t i)
{
	char		*format;
	t_param		set;

	ft_bzero(&set, sizeof(set));
	obj->p = set;
	format = obj->str;
	{
		i += (format[i] == '%');
		i += set_flags(&set.flags, &format[i], 0);
		set.tick |= !!set.flags << 0;
		i += set_width(&set.width, &set.precision, &format[i], obj);
		set.tick |= obj->p.tick;
		i += set_length(&set.length, &format[i], 0);
		set.tick |= !!set.length << 3;
		obj->p = set;
		select_function(obj, *(obj->str = &format[i]), 0);
	}
	return (1);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
