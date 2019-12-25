/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:08:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/20 19:40:25 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n >= 0 ? n : -n;
	if ((res = ft_strnew(ft_nbrlen(n) + (n < 0 ? 1 : 0))) == NULL)
		return (NULL);
	i = 0;
	res[i] = '0';
	while (num / 10 != 0 || num % 10 != 0)
	{
		res[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		res[i] = '-';
	ft_strrev(res);
	return (res);
}
