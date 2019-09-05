/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_output.c.m                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:05 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 23:58:36 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	output_o(t_format *o)
{
	t_list	*node;
	char	*str;

	node = o->list;
	while (node)
	{
		o->count += ft_strlen(((t_str*)node->content)->str);
		node = node->next;
	}
	if (!(str = ft_strnew(o->count)))
		ft_error("ft-printf: output allocation error");
	node = o->list;
	while (node)
	{
		ft_strncat(str, ((t_str*)node->content)->str,
			((t_str*)node->content)->length);
		node = node->next;
	}
	while (o->list)
	{
		node = o->list->next;
		tstr_free(o->list->content);
		free(o->list);
		o->list = node;
	}
	write(1, str, o->count);
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
	t_str	*node;

	if (!(node = tstr_new(NULL)))
		return (ft_error("ft-printf: append allocation error."));
	node->str = o->v;
	node->length = o->len;
	ft_lstpush(
		&o->list,
		ft_lstnew(
			node,
			sizeof(t_str)));
}
