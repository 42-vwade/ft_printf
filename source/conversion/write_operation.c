/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 07:25:19 by viwade            #+#    #+#             */
/*   Updated: 2019/05/09 07:37:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

size_t	ftprintf_write(char *s, size_t len, t_format *o)
{
	size_t	wr;

	wr = 0;
	if (*s)
		wr = write(1, s, len);
	o->count += wr;
	return (wr);
}
