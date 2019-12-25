/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:22:14 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/27 18:38:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_spaces_len(t_conv_spec *conv_spec, int nbr_len,
	__uint64_t hex_nbr)
{
	int width;
	int precision;
	int ret;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	ret = width - ft_max(precision, nbr_len);
	ret -= (conv_spec->flags & FLAG_PLUS) ? 1 : 0;
	ret -= (conv_spec->flags & FLAG_HASH) && hex_nbr ? 2 : 0;
	return (ret > 0 ? ret : 0);
}

static int	get_zeros_len(t_conv_spec *conv_spec, int nbr_len,
	__uint64_t hex_nbr)
{
	int width;
	int precision;
	int ret;
	int is_prefix_printed;
	int flags;

	precision = conv_spec->precision;
	width = conv_spec->width;
	flags = conv_spec->flags;
	is_prefix_printed = (flags & FLAG_HASH) && hex_nbr &&
		(flags & FLAG_ZERO) && conv_spec->precision < nbr_len ? 2 : 0;
	if (conv_spec->is_pset)
	{
		ret = precision - nbr_len - is_prefix_printed;
		return (ret > 0 ? ret : 0);
	}
	if (conv_spec->flags & FLAG_ZERO)
	{
		ret = width - nbr_len - is_prefix_printed;
		ret -= (conv_spec->flags & FLAG_PLUS) ? 1 : 0;
		return (ret > 0 ? ret : 0);
	}
	return (0);
}

int			conv_x(t_conv_spec *conv_spec, va_list *ap)
{
	__uint64_t	hex_nbr;
	int			nbr_len;
	int			spaces;
	int			zeros;

	hex_nbr = read_uint(ap, conv_spec->length);
	nbr_len = ft_nbrlen_base(hex_nbr, 16);
	if (conv_spec->is_pset && conv_spec->precision == 0 && hex_nbr == 0)
		nbr_len = 0;
	spaces = get_spaces_len(conv_spec, nbr_len, hex_nbr);
	zeros = get_zeros_len(conv_spec, nbr_len, hex_nbr);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if (conv_spec->flags & FLAG_HASH && hex_nbr != 0)
		ft_write_buff((conv_spec->conv_char == 'x' ? "0x" : "0X"), 2);
	ft_putnchar('0', zeros);
	if (!(conv_spec->is_pset && conv_spec->precision == 0 && hex_nbr == 0))
		ft_putunbr_base(hex_nbr, 16, conv_spec->conv_char == 'X');
	conv_spec->flags & FLAG_MINUS ? ft_putnchar(' ', spaces) : 0;
	return (spaces + zeros + nbr_len +
		((conv_spec->flags & FLAG_HASH) && hex_nbr ? 2 : 0));
}
