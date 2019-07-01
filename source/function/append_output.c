/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:05 by viwade            #+#    #+#             */
/*   Updated: 2019/06/26 19:08:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	output_o(t_format *o)
{
	write(1, o->out, o->count);
}

char
	*graft_o(t_list *start)
{
	char	*new;
	char	*graft;
	t_list	*node;

	new = NULL;
	node = start;
	while (node)
	{
		if (((t_str*)node->content)->str)
			graft = ft_strsub(
				((t_str*)node->content)->str,
				0,
				((t_str*)node->content)->length);
		new = ft_strjoin_free(new, graft);
		node = node->next;
	}
	return (new);
}

void
	append_o(t_format *o)
{
	if (o->len ? o->len : (o->len = ft_strlen(o->v)))
	{
		o->out = ft_strncat(o->out, o->v, o->len);
		o->count += o->len;
	}
	o->len = 0;
	if (o->free)
		ft_free(o->v);
}
