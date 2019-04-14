/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/04/14 02:52:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

/*
**  ENUMERATION
*/

/*
**  TYPE DEFINITIONS
*/

typedef struct s_format	t_format;
typedef struct s_param	t_param;

/*
**  STRUCTS
*/

struct	s_format
{
	va_list		args;
	char		*string;
	uint64_t	count;
};

struct	s_param
{
	uint8_t flags;
	width;
	precision;
	length;
};

#endif
