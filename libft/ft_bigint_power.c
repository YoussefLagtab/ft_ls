/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:33:39 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/25 18:25:58 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint	*ft_bigint_power(unsigned int b, unsigned int exp)
{
	t_bigint	*res;
	t_bigint	*base;

	if ((base = ft_bigint_from_uint128(b)) == NULL)
		return (NULL);
	if (exp <= 0)
		return (ft_bigint_from_uint128(1));
	else if (exp == 1)
		return (base);
	if ((res = (ft_bigint_from_uint128(1))) == NULL)
		return (NULL);
	while (exp > 1)
	{
		if (exp % 2 && (exp-- || 1))
			if ((res = ft_bigint_mult(res, base)) == NULL)
				return (NULL);
		exp /= 2;
		if ((base = ft_bigint_mult(base, base)) == NULL)
			return (NULL);
	}
	if ((res = ft_bigint_mult(res, base)) == NULL)
		return (NULL);
	return (res);
}
