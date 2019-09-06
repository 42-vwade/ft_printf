/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:26:11 by viwade            #+#    #+#             */
/*   Updated: 2019/09/05 23:37:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static char
	*decode_str(const char *s, size_t *write)
{
	char	buf[2];
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	buf[1] = 0;
	len = ft_strlen(s);
	MATCH(!(new = ft_strnew(len / 2)), ft_error("fatal: decode string failed"));
	while (s[i] && s[i + 1] && i < len)
	{
		buf[0] = (s[i] & 0x0f) | ((s[i + 1] & 0x0f) << 4);
		ft_strcat(&new[i], buf);
		i += 1;
	}
	write[0] = len / 2;
	return (new);
}

static char
	*encode_str(const char *s)
{
	char	buf[3];
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	buf[2] = 0;
	len = ft_strlen(s) || 1;
	MATCH(!(new = ft_strnew(len * 2)), ft_error("fatal: encode string failed"));
	while (s[i] && i < len)
	{
		buf[0] = 0xf0 | (s[i] & 0x0f);
		buf[1] = 0xf0 | (s[i] >> 4);
		ft_strcat(&new[i * 2], buf);
		i += 1;
	}
	return (new);
}

char
	*encode_output(const char *data, const char *output)
{
	MATCH(!data, data = ft_append(data, encode_str(output), 2));
	ELSE(data = ft_append(data, encode_str(output), 3));
	ft_memdel((void**)&output);
	return ((char*)data);
}

char
	*decode_output(const char *data, size_t *len)
{
	void	*tmp;

	tmp = (char*)data;
	data = ft_append(NULL, decode_str(data, len), 2);
	ft_memdel(&tmp);
	return ((char*)data);
}
