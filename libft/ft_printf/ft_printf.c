/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:03 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/10 16:24:42 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	clean_up(va_list *ap)
{
	va_end(*ap);
	ft_autofree_all();
	ft_flush_buff();
}

int			ft_printf(char *format, ...)
{
	va_list ap;
	int		parse_ret;
	int		ret;

	ret = 0;
	parse_ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			parse_ret = parse_conversion(&format, &ap);
			if (parse_ret == -1)
				break ;
			else
				ret += parse_ret;
			continue;
		}
		else
			ret += ft_write_buff(format++, 1);
	}
	clean_up(&ap);
	return (parse_ret == -1 ? -1 : ret);
}
