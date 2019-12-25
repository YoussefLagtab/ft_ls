/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:49:44 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/22 15:05:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (result < 0)
		return (sign > 0 ? -1 : 0);
	result *= sign;
	return (result);
}
