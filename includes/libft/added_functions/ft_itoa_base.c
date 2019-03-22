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
#define BASE_LOWER "0123456789abcdef"
#define BASE_UPPER "0123456789ABCDEF"
#define ABS(x) ((x) < 0) ? -(x) : (x)
#define ITOA_SIZE(x) ((x) < 0) ? 3 : 2

char	*ft_itoa_base(int n, int base)
{
	int		len;
	int		tmp;
	int		size;
	char	*str;
	char	*key;

	len = 0;
	key = BASE_LOWER;
	size = ITOA_SIZE(n * (base == 10));
	tmp = n;
	while (tmp /= base)
		len++;
	len += size;
	if ((str = (char *)malloc(len * sizeof(*str))))
	{
		str[--len] = 0;
		while (str < (&(str[len--] = key[ABS(n) % base])))
			n /= base;
		if (size == 3)
			str[0] = '-';	
	}
	return (str);
}
