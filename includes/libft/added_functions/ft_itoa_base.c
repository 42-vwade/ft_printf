/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:58:04 by viwade            #+#    #+#             */
/*   Updated: 2019/03/25 15:00:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define BASE16_LOWER "0123456789abcdef"
#define BASE16_UPPER "0123456789ABCDEF"
#define ABS(x) ((x) < 0) ? -(x) : (x)
#define FT_ITOA_SIZE(x) ((x) < 0) ? 3 : 2
#define FT_ITOA_PUT(k,n,b,a) (a) = (k)[ABS(n) % b]; n /= b

char	*ft_itoa_base(int n, int base)
{
	int		len;
	int		tmp;
	int		size;
	char	*str;
	char	*key;

	len = 0;
	key = BASE16_LOWER;
	size = FT_ITOA_SIZE(n * (base == 10));
	tmp = n;
	while (tmp /= base)
		len++;
	len += size;
	if ((str = (char *)malloc(len * sizeof(*str))))
	{
		str[--len] = 0;
		while (len--)
		{
			str[len] = key[ABS(n) % base];
			n /= base;
		}
		if (size == 3)
			str[0] = '-';
	}
	return (str);
}
