/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/02/27 17:44:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef t_param	t_context_t;

static int
	set_flag(char set, char *s)
{
	char	*str;

	str = (char *){"-+ #0"};
	while (*str)
		if (*str == *s)
		{
			set = *str;
			return (1);
		}
		else
			str++;
	set = 0;
	return (0);
}

static int
	set_width(t_width *w, char *s)
{
	w[0].key = 0;
	if ((w[0].width = (*s == '*')))
		w[0].key = '*';
	else if (ft_isdigit(*s))
		w[0].width = ft_atoi(s);
	else if ((w[0].key = -1) == -1)
		return (0);
	return (ft_intlen(w[0].width));
}

static int
	set_precision(t_width *w, char *s)
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
	set_specifier(uint8_t sb, char set, char *s)
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
	get_params(char *option, t_param **set)
{
	uint64_t	i;
	uint64_t	error;

	i = 0;
	error = 0;
	if ((set[0] = (t_param *)malloc(sizeof(*set[0]))))
	{
		i += (option[i] == '%');
		i += set_flag(set[0]->flag, &option[i]);
		i += set_width(&set[0]->width, &option[i]);
		error += (set[0]->width.key == -1);
		i += set_precision(&set[0]->precision, &option[i]);
		error += (set[0]->precision.key == -1);
		i += set_specifier(set[0]->sub, set[0]->spec, &option[i]);
		error += !(ft_strchr(FT_SPEC, set[0]->spec));
		set[0]->param_len = i;
	}
	return (error ? -1 : set[0]->param_len);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
