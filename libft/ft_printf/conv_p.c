/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 04:21:25 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 18:21:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_p(t_conv_spec *conv_spec, va_list *ap)
{
	va_list ap2;

	va_copy(ap2, *ap);
	if (va_arg(ap2, long int) == 0)
	{
		if (conv_spec->width && (conv_spec->flags & FLAG_MINUS) == 0)
			ft_putnchar(' ', conv_spec->width - 3);
		ft_write_buff("0x0", 3);
		if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
			ft_putnchar(' ', conv_spec->width - 3);
		va_end(ap2);
		return (ft_max(conv_spec->width, 3));
	}
	va_end(ap2);
	conv_spec->length = L;
	conv_spec->flags |= FLAG_HASH;
	conv_spec->conv_char = 'x';
	return (conv_x(conv_spec, ap));
}
