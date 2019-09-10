/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 03:41:28 by viwade            #+#    #+#             */
/*   Updated: 2019/04/24 00:08:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int
	isdelim(char c, char d)
{
	if (!c)
		return (0);
	return (c == d);
}

unsigned int
	ft_delimit(char *s, char c)
{
	unsigned int	i;
	unsigned int	num;

	i = 0;
	num = 0;
	while (s[i])
		if (!isdelim(s[i], c) && (num += 1))
			while (!isdelim(s[i], c) && s[i])
				++i;
		else
			while (isdelim(s[i], c))
				++i;
	return (num);
}
