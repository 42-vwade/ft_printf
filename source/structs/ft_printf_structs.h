/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 03:08:22 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# define U_DOUBLE typedef union u_double	u_double
# define SPECIFIER_LIST	"%cspdiouxfeganb"

/*
**	ENUMERATION
*/

enum	e_flags {
	plus = 1 << 0,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4,
	neg = 1 << 7
};

enum	e_length {
	hh = 1 << 0,
	h = 1 << 1,
	l = 1 << 2,
	ll = 1 << 3,
	j = 1 << 4,
	z = 1 << 5,
	t = 1 << 6,
	LD = 1 << 7
};

/*
**	UNION STRUCT
*/

U_DOUBLE;

union	u_double
{
	ULL		ld;
	double	d;
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

typedef int	(*t_func) (t_format *);

/*
**	STRUCTS
*/
struct	s_param
{
	ull_t	tick;
	ull_t	flags;
	ull_t	width;
	ull_t	precision;
	ull_t	length;
};

struct	s_format
{
	va_list		ap;
	const char	*format;
	t_func		jump[256];
	t_func		f;
	t_param		p;
	char		*sign;
	char		*z_pad;
	char		*pad;
	t_list		*list;
	char		*str;
	size_t		len;
	size_t		count;
	int			error;
	void		*v;
	void		*output;
};

struct	s_type
{
	char	type;
	t_func	f;
};

#endif
