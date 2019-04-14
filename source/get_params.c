/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/04/14 03:33:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef t_param	t_context_t;

static int
	set_flags(char *set, const char *s)
{
	uint	i;
	char	*str;

	i = 0;
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
	set_width(uint32_t *w, const char *s, t_format *o, uint32_t i)
{
	w[0] = 0;
	if (s[i] == '*')))
		w[0] = va_arg(o->arg, int);
	else if (ft_isdigit(*s))
		w[0].width = ft_atoi(s);

    return (ft_intlen(w[0].width));
}

static int
	set_precision(t_width *w, const char *s)
{
	w[0].key = 0;
	if ((w[0].width = (s[1] == '*')) && s[0] == '.')
		w[0].key = '*';
	else if (ft_isdigit(s[1]) && s[0] == '.')
		w[0].width = ft_atoi(&s[1]);
	else if (s[0] == '.')
		w[0].key = '0';
	else if ((w[0].key = -1) == -1)
		return (0);
	return (ft_intlen(w[0].width));
}

/*
**	^^^^	For width and precision settings	^^^^
**
**	Return values (key)
**	key = '*'	//	get next argument as value to replace 'width'
**	key = '0'	//	set value to default of zero : width = 0;
**	key = 0		//	get value from 'width' parameter
**	key = -1	//	no operation shall take place
*/

static int
	set_specifier(uint8_t sb, char set, const char *s)
{
	int		i;
	char	*spec;
	char	*option;

	i = 0;
	spec = (char *){FT_SPEC};
	option = (char *){FT_SUBSPEC};
	while (option[i])
		if (s[0] == option[i])
			sb = (i < 2) ? ((s[1] == option[i]) << 7 | option[i]) : option[i];
		else
			++i;
}

int
	get_params(t_format *obj, t_param *set)
{
	uint64_t	i;
	char    *format;

	i = 0;
    format = obj->str;
	{
		i += (format[i] == '%');
		i += set_flags(set->flags, &format[i]);
		i += set_width(&set->width, &format[i], obj, 0);
		error += (set->width.key == -1);
		i += set_precision(&set->precision, &format[i]);
		error += (set->precision.key == -1);
		i += set_specifier(set->sub, set->spec, &format[i]);
		error += !(ft_strchr(FT_SPEC, set->spec));
		set->param_len = i;
	}
	return (error ? -1 : set->param_len);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
