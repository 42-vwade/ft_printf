/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:13:30 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 13:23:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <string.h>

/*
**	Set function.
**	Function sets a value through n bytes of memory, starting from a point.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*dup;

	i = 0;
	while (len--)
	{
		dup = &((char *)b)[i];
		dup[0] = (char)c;
		i++;
	}
	return (b);
}
