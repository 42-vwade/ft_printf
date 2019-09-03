/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2019/08/02 14:10:45 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define _HB(a,b)	{{a};{b}
#define _RR		return;
#define H_V0(o) ft_strnew(0)
#define H_V1(o) ft_tolower(o->str[0])
#define H_V2(o) !!ft_atoi(o->v)
#define H_V3(o) ft_strdup("0")
#define H_V4(o) (o->p.tick & 4 && !o->p.precision)
#define HSH1(o,c,nz) (c=='x'&&nz)?
#define HSH0(o,c,nz) (c=='o'&&!(!nz&&H_V4(o))) ? H_V3(o) : HSH1(o,c,nz)
#define HASH_O(o,f) (8U & f) ? HSH0(o, H_V1(o), H_V2(o)) : H_V0(o)

/*
**	o->len == precalculated before calling width_o;
**	;
*/

static void
	determine_width(t_format *o, char *hash)
{
	size_t	len[2];

	len[0] = ft_strlen(o->v);
	len[1] = ft_strlen(hash);
	o->p.width = MAX((LL)(o->p.width - len[0] - len[1]), 0);
}

static void
	apply_man(t_format *o, char *hash, ull_t f, ull_t *w)
{
	char	*pad;
	char	z;

	z = f & zero && !(ft_strchr("diouxp", ft_tolower(*o->str)) && w[2] & 4);
	pad = ft_memset(ft_strnew(w[0]), z ? '0' : ' ', w[0]);
	if (z)
		_B(_B(ft_strchr("+- ", *(char*)o->v) ? ft_swap(pad, o->v) : 0,
		o->v = hash && ft_strchr("oxp", ft_tolower(*o->str)) ?
			ft_strjoin_free(ft_strjoin_free(hash, pad), o->v) :
			ft_strjoin_free(pad, o->v)), _RR);
	IF_E(f & minus,
		o->v = ft_strjoin_free(hash ? ft_strjoin_free(hash, o->v) : o->v, pad),
		o->v = ft_strjoin_free(pad, hash ? ft_strjoin_free(hash, o->v) : o->v));
	o->v = ft_isuppercase(o->str[0]) ? ft_strcapitalize(o->v) : o->v;
}

static void
	handle_signs(t_format *o, char **hash)
{
	hash[0] = 0;
	if (plus & o->p.flags && !(neg & o->p.flags) && *(char*)o->v != '+')
		o->v = ft_strjoin_free(ft_strdup("+"), o->v);
	else if (ft_tolower(*o->str) == 'p')
		hash[0] = ft_strdup("0x");
}

void
	width_o(t_format *o)
{
	char	*hash;

	handle_signs(o, &hash);
	determine_width(o, hash = !hash ? hash_o(o) : hash);
	if (!o->p.width && !hash)
		return ;
	if (!o->p.width)
		_B(o->v = ft_strjoin_free(hash, o->v), _RR);
	apply_man(o, hash, o->p.flags,
	(ull_t[]){o->p.width, o->p.precision, o->p.tick});
}
