/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:10:32 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/25 18:24:06 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_float_type(t_conv_spec *conv_spec, t_float_specs *f_specs)
{
	if (f_specs->ldbl.s.e == 0x7fff && bit_is_set(f_specs->ldbl.s.m, 63) &&
			(f_specs->ldbl.s.m << 1) == 0)
		return (INF);
	if ((f_specs->ldbl.s.e && !bit_is_set(f_specs->ldbl.s.m, 63))
			|| (f_specs->ldbl.s.e == 0x7fff && bit_is_set(f_specs->ldbl.s.m, 63)
			&& (f_specs->ldbl.s.m << 1)))
		return (NAN);
	if (f_specs->ldbl.s.e == 0 && f_specs->ldbl.s.m == 0)
	{
		if ((f_specs->whole = ft_bigint_new(1)) == NULL)
			return (-1);
		if ((f_specs->frac = ft_bigint_new(conv_spec->precision)) == NULL)
			return (-1);
		return (ZERO);
	}
	return (FLOAT);
}

int		print_float_prefix(t_conv_spec *conv_spec, int float_sign)
{
	int ret;

	ret = 0;
	if ((conv_spec->flags & FLAG_PLUS) || float_sign)
		ret = ft_putchar(float_sign ? '-' : '+');
	else if (conv_spec->flags & FLAG_SPACE)
		ret = ft_putchar(' ');
	return (ret);
}
