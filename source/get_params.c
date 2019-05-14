/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/05/14 00:25:59 by viwade           ###   ########.fr       */
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
		if (s[i - 1] == plus)
			set[0] |= 1 << 0;
		else if (s[i - 1] == minus)
			set[0] |= 1 << 1;
		else if (s[i - 1] == zero)
			set[0] |= 1 << 2;
		else if (s[i - 1] == hash)
			set[0] |= 1 << 3;
		else if (s[i - 1] == space)
			set[0] |= 1 << 4;
		else
			return (i - 1);
	return (i);
}

static int
	set_width(size_t *w, size_t *p, const char *s, t_format *o)
{
	uint	i;

	i = 0;
	if (s[i] == '*')
		w[0] = (int)va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		w[0] = ft_atoi(&s[i]);
	i += (s[i] == '*') || ft_isdigit(s[i]) ? ft_intlen(w[0]) : 0;
	if (s[i++] != '.')
		return (i - 1);
	if (s[i] == '*')
		p[0] = (int)va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		p[0] = ft_atoi(&s[i]);
	i += (s[i] == '*') ? 1 : ft_intlen(p[0]);
	return (i);
}

static int
	set_length(uint8_t *l, const char *s, uint i)
{
	l[0] = 0;
	if (s[i] == 'h')
		l[0] |= (s[i + 1] == 'h') ? hh : h;
	else if (s[i] == 'l')
		l[0] |= (s[i + 1] == 'l') ? ll : 1 << 2;
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
	o->p.f = ft_isuppercase(c);
	while (g_dispatch[i++].type)
		if (!g_dispatch[i - 1].type)
			ft_error("ft_printf: No valid parameter found. Exiting.");
		else if (g_dispatch[i - 1].type == c)
		{
			o->count += g_dispatch[i - 1].f(o->arg, o);
			break ;
		}
}

int
	get_params(t_format *obj, size_t i)
{
	char		*format;
	t_param		set;

	ft_bzero(&set, sizeof(set));
	format = obj->str;
	{
		i += (format[i] == '%');
		i += set_flags(&set.flags, &format[i], 0);
		i += set_width(&(set.width), &(set.precision), &format[i], obj);
		i += set_length(&set.length, &format[i], 0);
		obj->p = set;
		select_function(obj, *(obj->str = &format[i]), 0);
	}
	return (1);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
