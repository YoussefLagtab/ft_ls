/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/10 16:26:06 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_spaces(t_conv_spec *conv_spec, t_specs specs)
{
	int width;
	int precision;
	int ret;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset && conv_spec->precision == 0 && specs.unbr == 0)
		specs.unbr_len = 0;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	ret = width - ft_max(precision, specs.unbr_len) -
		(specs.sign || (conv_spec->flags & (FLAG_PLUS | FLAG_SPACE)));
	return (ret > 0 ? ret : 0);
}

static int	get_zeros(t_conv_spec *conv_spec, t_specs specs)
{
	int width;
	int precision;
	int ret;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
	{
		ret = precision - specs.unbr_len;
		return (ret > 0 ? ret : 0);
	}
	if (conv_spec->flags & FLAG_ZERO)
	{
		ret = width - specs.unbr_len -
			(specs.sign || (conv_spec->flags & (FLAG_PLUS | FLAG_SPACE)));
		return (ret > 0 ? ret : 0);
	}
	return (0);
}

static int	get_printed_len(t_conv_spec *conv_spec, t_specs specs)
{
	if (conv_spec->is_pset && conv_spec->precision == 0 && specs.unbr == 0)
		specs.unbr_len = 0;
	return (specs.spaces + specs.zeros + specs.unbr_len +
			(specs.sign || (conv_spec->flags & (FLAG_PLUS | FLAG_SPACE))));
}

static void	read_unbr(va_list *ap, t_length len, t_specs *specs)
{
	__int64_t	nbr;

	nbr = read_int(ap, len);
	if (nbr < 0)
		specs->unbr = (__uint64_t)(nbr * -1);
	else
		specs->unbr = (__uint64_t)nbr;
	specs->unbr_len = specs->unbr == 0 ? 1 : ft_nbrlen(specs->unbr);
	specs->sign = nbr < 0;
}

int			conv_di(t_conv_spec *conv_spec, va_list *ap)
{
	t_specs specs;

	read_unbr(ap, conv_spec->length, &specs);
	specs.spaces = get_spaces(conv_spec, specs);
	specs.zeros = get_zeros(conv_spec, specs);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', specs.spaces);
	if ((conv_spec->flags & FLAG_SPACE) && specs.sign == 0)
		ft_putchar(' ');
	if ((conv_spec->flags & FLAG_PLUS) || specs.sign)
		ft_putchar(specs.sign ? '-' : '+');
	ft_putnchar('0', specs.zeros);
	if (!(conv_spec->is_pset && conv_spec->precision == 0 && specs.unbr == 0))
		ft_putunbr(specs.unbr);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', specs.spaces);
	return (get_printed_len(conv_spec, specs));
}
