/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/08/05 23:23:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "global.h"

typedef t_param	t_context_t;

static int
	set_flags(ull_t *set, const char *s, uint i, size_t len)
{
	set[0] = 0;
	while (&s[i++] < &s[len])
		if (s[i - 1] == '+')
			set[0] = (set[0] | plus) & ~(space);
		else if (s[i - 1] == '-')
			set[0] = (set[0] | minus) & ~(zero);
		else if (s[i - 1] == '0')
			set[0] |= !(minus & set[0]) << 2;
		else if (s[i - 1] == '#')
			set[0] |= 1 << 3;
		else if (s[i - 1] == ' ')
			set[0] |= !(plus & set[0]) << 4;
		else if ((s[i - 1] == '.' || ('1' <= s[i - 1] && s[i - 1] <= '9')))
			while ((&s[i - 1] < &s[len] && (('0' <= s[i - 1] && s[i - 1] <= '9')
					|| s[i - 1] == '.')))
				i++;
	return (1);
}

static int
	set_width(t_format *o, const char *s, size_t len)
{
	size_t	i;
	char	move;

	i = 0;
	while (s < &s[len] && !(('1' <= *s && *s <= '9') || *s == '.'))
		s++;
	if (s[i] == '*')
		o->p.width = (int)va_arg(o->ap, int);
	else if (ft_isdigit(s[i]))
		o->p.width = ft_atoi(&s[i]);
	if ((o->p.tick |= !!o->p.width << 1) & 1 << 1)
		i += (s[i] == '*') ? 1 : ft_intlen(o->p.width);
	IF_C(s[i++] != '.', return (i - 1););
	o->p.tick |= 1 << 2;
	if ((move = s[i] == '*'))
		o->p.precision = (int)va_arg(o->ap, int);
	else if ((move = 2 * ft_isdigit(s[i])))
		o->p.precision = ft_atoi(&s[i]);
	IF_C(move, i += (s[i] == '*') ? 1 : ft_intlen(o->p.precision););
}

/*
**	Returns zero if length parameter is not modified.
**	Otherwise, a length is determined, returned, and a specific flag is set.
*/

FT_SIZE
	set_length(ull_t *l, const char *s, uint i, size_t len)
{
	l[0] = 0;
	while (!ft_strchr("hljzL", *s) && s < &s[len])
		s++;
	if (s[i] == 'h')
		l[0] = (s[i + 1] == 'h') ? hh : h;
	else if (s[i] == 'L')
		l[0] = LD;
	else if (s[i] == 'l')
		l[0] = (ft_tolower(s[i + 1]) == 'l') ? ll : 1 << 2;
	else if (s[i] == 'j')
		l[0] = j;
	else if (s[i] == 'z')
		l[0] = z;
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
	c = ft_tolower(c);
	if (g_table[(int)c])
		g_table[(int)c](o);
	else
		ft_error("ft_printf: No valid parameter found. Exiting.");
	return ;
	while (g_dispatch[i++].type)
		if (g_dispatch[i - 1].type == ft_tolower(c))
		{
			g_dispatch[i - 1].f(o);
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
	obj->len = 1;
	format = obj->str;
	{
		while (format[obj->len] && !g_table[(int)format[obj->len]])
			obj->len++;
		i = obj->len + 1;
		set_flags(&set.flags, &format[1], 0, obj->len);
		set.tick |= !!set.flags << 0;
		set_width(obj, &format[1], obj->len);
		set.tick |= obj->p.tick;
		set_length(&set.length, &format[1], 0, obj->len);
		set.tick |= !!set.length << 3;
		obj->p = set;
		select_function(
			obj, *(obj->str = &format[obj->len]), 0);
	}
	return (i);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
