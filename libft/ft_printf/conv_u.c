/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:44:55 by ylagtab           #+#    #+#             */
/*   Updated: 2019/12/10 16:24:15 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_spaces(t_conv_spec *conv_spec, t_specs *specs)
{
	int width;
	int precision;
	int ret;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset && conv_spec->precision == 0 && specs->unbr == 0)
		specs->unbr_len = 0;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	ret = width - ft_max(precision, specs->unbr_len);
	return (ret > 0 ? ret : 0);
}

static int	get_zeros(t_conv_spec *conv_spec, t_specs *specs)
{
	int width;
	int precision;
	int ret;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
	{
		ret = precision - specs->unbr_len;
		return (ret > 0 ? ret : 0);
	}
	if (conv_spec->flags & FLAG_ZERO)
	{
		ret = width - specs->unbr_len;
		return (ret > 0 ? ret : 0);
	}
	return (0);
}

static int	get_printed_len(t_conv_spec *conv_spec, t_specs specs)
{
	if (conv_spec->is_pset && conv_spec->precision == 0 && specs.unbr == 0)
		specs.unbr_len = 0;
	return (specs.spaces + specs.zeros + specs.unbr_len);
}

static void	read_unbr(va_list *ap, t_length len, t_specs *specs)
{
	specs->unbr = read_uint(ap, len);
	specs->unbr_len = specs->unbr == 0 ? 1 : ft_nbrlen(specs->unbr);
	specs->sign = 0;
}

int			conv_u(t_conv_spec *conv_spec, va_list *ap)
{
	t_specs specs;

	read_unbr(ap, conv_spec->length, &specs);
	specs.spaces = get_spaces(conv_spec, &specs);
	specs.zeros = get_zeros(conv_spec, &specs);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', specs.spaces);
	ft_putnchar('0', specs.zeros);
	if (!(conv_spec->is_pset && conv_spec->precision == 0 && specs.unbr == 0))
		ft_putunbr(specs.unbr);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', specs.spaces);
	return (get_printed_len(conv_spec, specs));
}
