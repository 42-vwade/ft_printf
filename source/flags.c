/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:01:24 by viwade            #+#    #+#             */
/*   Updated: 2019/02/20 09:38:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*spec = (char *){"diuoxXfFeEgGaAcspn%"};
char	*subs = (char *){"hljztL"};


static char
	getflag(char c)
{
	char	*flag;

	flag = (char [6]){'-', '+', ' ', '#', '0', 0};
	while (*flag)
		if (c == (flag++)[0])
			return (flag[0]);
	return (0);
}

static char
	*specifier(char *s)
{
	int 	*i;
	int		*f;
	char	*spec;
	char	**subs;

	i = (int [2]){0, 0};
	f = (int [5]){0, 0, 0, 0, 0};
	dubsub = "hl";
	while ()
		if ( == flag[i][0])
			f[0] = i;
	while (i < 8)
		if (ft_strstr(s, ))
			;
}

/*
**	UNNEDED FLAGS ARE
**	eEgGaAjzt?
*/
static char
	known_flags(char *s)
{
	int		i;

	i = 0;
	if (s[i])
		;
}

/*
**	format specifier prototype
**	%[flags][width][.precision][length]specifier
**	[specifier] is required
*/

t_list
	*search_flags(char *s)
{
	int		i;
	char	flag;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			known_flags(&s[i]);
	}
}
