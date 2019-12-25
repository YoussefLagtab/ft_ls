/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:10:42 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/25 18:23:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint	*ft_bigint_mult(t_bigint *a, t_bigint *b)
{
	t_bigint		*res;
	unsigned int	i;
	unsigned int	j;

	if (a == NULL || b == NULL)
		return (NULL);
	if ((res = ft_bigint_new(a->length + b->length)) == NULL)
		return (NULL);
	i = 0;
	while (i < b->length)
	{
		j = 0;
		while (j < a->length)
		{
			res->digits[i + j] += b->digits[i] * a->digits[j];
			res->digits[i + j + 1] += res->digits[i + j] / 10;
			res->digits[i + j] %= 10;
			j++;
		}
		i++;
	}
	return (res);
}
