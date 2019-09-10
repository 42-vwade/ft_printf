/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstr_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:59:12 by viwade            #+#    #+#             */
/*   Updated: 2019/09/05 23:34:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bstr_t
	ft_append_bstr(const char *s1, const char *s2, int mode)
{
	bstr_t	binary;

	binary = (bstr_t){0, 0};
	if (mode == 'c')
	{
		MATCH(!s2[0], binary.length = ft_strlen(s1) + 1);
		OR(!s1[0], binary.length = ft_strlen(s2) + 1);
		ELSE(binary.length = ft_strlen(s1) + ft_strlen(s2));
		binary.data = ft_strnew(binary.length);
	}
	return (binary);
}
