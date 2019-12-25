/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:31 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/25 18:34:46 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	increment_float(t_bigint **whole, t_bigint **frac, int precision)
{
	unsigned int	frac_part_length;
	t_bigint		*added_number;

	if (precision == 0)
	{
		if ((*whole = ft_bigint_add(*whole, ft_bigint_from_uint128(1))) == NULL)
			return (-1);
		(*frac)->length = 0;
		return (0);
	}
	frac_part_length = (*frac)->length;
	if ((added_number = ft_bigint_new((*frac)->length - precision + 1)) == NULL)
		return (-1);
	added_number->digits[added_number->length - 1] = 1;
	if ((*frac = ft_bigint_add(*frac, added_number)) == NULL)
		return (-1);
	if (frac_part_length < (*frac)->length)
	{
		if ((*whole = ft_bigint_add(*whole, ft_bigint_from_uint128(1))) == NULL)
			return (-1);
		if ((*frac = ft_bigint_new(1)) == NULL)
			return (-1);
	}
	return (0);
}

static int	str_iszero(char *str, int len)
{
	while (len--)
		if (str[len] != 0)
			return (0);
	return (1);
}

int			round_float(t_bigint **whole, t_bigint **frac, int precis)
{
	int	index;

	index = (*frac)->length - precis - 1;
	if (index < 0)
		return (0);
	if ((*frac)->digits[index] > 5 && increment_float(whole, frac, precis) < 0)
		return (-1);
	if ((*frac)->digits[index] == 5)
	{
		if ((precis == 0 && (*whole)->digits[0] % 2)
				|| (precis != 0 && (*frac)->digits[index + 1] % 2))
		{
			if (increment_float(whole, frac, precis) == -1)
				return (-1);
		}
		else
		{
			if (str_iszero((*frac)->digits, index) == 0)
				if ((increment_float(whole, frac, precis)) == -1)
					return (-1);
		}
	}
	return (0);
}
