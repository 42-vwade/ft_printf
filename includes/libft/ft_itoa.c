/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:58:04 by viwade            #+#    #+#             */
/*   Updated: 2018/11/14 22:56:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	int		size;
	char	*str;

	len = 0;
	size = ((unsigned int)n < 0x80000000) ? 2 : 3;
	tmp = n;
	while (tmp /= 10)
		len++;
	len += size;
	if ((str = (char *)malloc(len * sizeof(*str))))
	{
		str[--len] = 0;
		while (len--)
		{
			str[len] = ((n < 0) ? -(n % 10) : n % 10) + 48;
			n /= 10;
		}
		if (size == 3)
			str[0] = '-';
	}
	return (str);
}
