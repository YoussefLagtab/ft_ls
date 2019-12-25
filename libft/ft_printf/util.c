/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:31:50 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/10 16:26:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_in_str(int c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int		bit_is_set(unsigned long nbr, int index)
{
	return (((nbr >> index) & 1) == 1);
}
