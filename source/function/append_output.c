/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:05 by viwade            #+#    #+#             */
/*   Updated: 2019/06/09 16:57:17 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	output_o(t_format *o, t_list *start)
{
	t_list	*node;

	node = start;
	while (node)
	{
		o->count += write(1, ((t_str*)node->content)->str,
			((t_str*)node->content)->length);
		node = node->next;
	}
	while (start)
	{
		node = start->next;
		tstr_free(start->content);
		free(start);
		start = node;
	}
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
	append_o(t_list *start, char *s, size_t len)
{
	t_str	*node;

	if (!(node = tstr_new(NULL)))
		return (ft_error("Memory allocation error."));
	node->str = s;
	node->length = len;
	ft_lstpush(
		start,
		ft_lstnew(
			node,
			sizeof(t_str)));
}
