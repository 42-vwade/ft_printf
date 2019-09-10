/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:02:07 by viwade            #+#    #+#             */
/*   Updated: 2019/06/03 08:45:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	FT_STR	new;

	new = ft_strjoin(s1, s2);
	ft_free((void*)s1);
	ft_free((void*)s2);
	return ((FT_STR)new);
}
