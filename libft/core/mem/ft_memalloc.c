/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:42:05 by viwade            #+#    #+#             */
/*   Updated: 2019/05/13 19:05:58 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if ((new = (void *)malloc(size)))
		ft_bzero(new, size);
	return (new);
}
