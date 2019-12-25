/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:47:09 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/27 18:12:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnchar(char c, int n)
{
	int ret;

	ret = 0;
	while (n-- > 0)
		ret += ft_write_buff(&c, 1);
	return (ret);
}
