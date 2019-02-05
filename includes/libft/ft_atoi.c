/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:54:25 by viwade            #+#    #+#             */
/*   Updated: 2018/11/14 22:44:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int		num;
	char				neg;

	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	neg = str[0];
	str += (neg == '-' || neg == '+') ? 1 : 0;
	while (*str >= '0' && *str <= '9')
		if ((unsigned long long)\
				(num = num * 10 + (*str++ - 48)) >= 0x7fffffffffffffff)
			return (-1 + (neg == '-'));
	return ((int)((neg == '-') ? -num : num));
}
