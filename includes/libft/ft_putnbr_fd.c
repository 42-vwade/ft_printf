/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:25:34 by viwade            #+#    #+#             */
/*   Updated: 2018/11/13 12:53:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void
	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		tmp;
	char	c;

	tmp = n;
	len = 1;
	if ((unsigned)n >= 0x80000000)
		write(fd, "-", 1);
	while (tmp /= 10)
		len *= 10;
	while (len)
	{
		c = ((n < 0) ? -(n / len) : n / len) + 48;
		write(fd, &c, 1);
		n %= len;
		len /= 10;
	}
}
