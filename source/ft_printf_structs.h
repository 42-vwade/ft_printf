/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/05/27 05:54:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>

/*
**	ENUMERATION
*/

enum	e_flags {
	plus = 1 << 0,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4
};

enum	e_length {
	hh	= 1 << 0,
	h	= 1 << 1,
	l	= 1 << 2,
	ll	= 1 << 3,
	j	= 1 << 4,
	z	= 1 << 5
};

enum	e_sample {
	blank,
	a,
	b,
	c,
	d
};

/*
**	TYPE DEFINITIONS
*/

typedef struct s_format	t_format;
typedef struct s_param	t_param;
typedef struct s_type	t_type;

/*
**	FUNCTION DEFINITION
*/

typedef int (*f_func) (t_format *);

/*
**	STRUCTS
*/
struct	s_param
{
	uint8_t		flags;
	int64_t		width;
	int64_t		precision;
	uint8_t		length;
	uint8_t		f;
};

struct	s_format
{
	va_list	arg;
	t_param	p;
	char	*str;
	size_t	count;
	void	*v;
};

struct	s_type
{
	char	type;
	f_func	f;
};

#endif
