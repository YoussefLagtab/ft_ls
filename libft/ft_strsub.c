/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:15:52 by mel-idri          #+#    #+#             */
/*   Updated: 2019/10/07 14:06:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new_str;

	if (s == NULL || (new_str = ft_strnew(len)) == NULL)
		return (NULL);
	return (ft_strncpy(new_str, s + start, len));
}
