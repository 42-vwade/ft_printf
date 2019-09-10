/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:23:33 by viwade            #+#    #+#             */
/*   Updated: 2019/05/13 19:06:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	if (!data)
		return (NULL);
	if ((elem = (t_list *)malloc(sizeof(*elem))))
	{
		elem->content = data;
		elem->next = NULL;
	}
	return (elem);
}
