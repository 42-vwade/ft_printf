/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:36:22 by viwade            #+#    #+#             */
/*   Updated: 2019/09/05 20:56:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H
# include <stdlib.h>

typedef struct s_byte_string	t_bstr;
typedef struct s_list	t_list;
typedef struct s_num	t_num;
typedef struct s_str	t_str;
typedef struct s_128b	t_128b;

struct	s_byte_string
{
	void	*data;
	size_t	length;
};

struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

struct	s_num
{
	size_t	length;
	char	*d;
};

struct	s_str
{
	char	*str;
	size_t	length;
	char	free:1;
};

struct	s_128b
{
	FT_ULL	a;
	FT_ULL	b;
};

#endif
