/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:11:26 by viwade            #+#    #+#             */
/*   Updated: 2019/05/13 19:05:58 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*tmp;

	i = 0;
	while (n--)
	{
		tmp = &((char *)dst)[i];
		tmp[0] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}
