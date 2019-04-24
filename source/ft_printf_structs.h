/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 06:10:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>

/*
**  ENUMERATION
*/

enum	e_flags {
	plus = '+',
	minus = '-',
	zero = '0',
	hash = '#',
	space = ' '
};

enum	e_length {
	h	= 0,
	hh	= 1 << 1,
	l	= 1 << 2,
	ll	= 1 << 3,
	j	= 1 << 4,
	z	= 1 << 5
};

/*
**  TYPE DEFINITIONS
*/

typedef struct s_format	t_format;
typedef struct s_param	t_param;
typedef struct s_type	t_type;

/*
**	FUNCTION DEFINITION
*/

typedef int (*f_func) (va_list, t_format *);

/*
**  STRUCTS
*/

struct	s_format
{
	va_list		arg;
	t_param		p;
	char		*str;
	uint64_t	count;
};

struct	s_param
{
	uint8_t flags;
	uint	width;
	uint	precision;
	uint	length;
};

struct	s_type
{
	char	type;
	f_func	f;
};

#endif
