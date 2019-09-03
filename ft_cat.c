/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:17:39 by viwade            #+#    #+#             */
/*   Updated: 2019/07/13 02:02:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int n, char **v)
{
	char	*line;

	line = NULL;
	if (n == 2)
	{
		int fd = open(v[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			ft_putendl(line);
		close(fd);
	}
}
