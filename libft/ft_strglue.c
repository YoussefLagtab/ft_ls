/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:11:54 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 15:25:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strglue(char const *s1, char glue, char const *s2)
{
	char	*new_str;
	size_t	len;
	size_t	s1_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	len = s1_len + 1 + ft_strlen(s2);
	if ((new_str = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strcpy(new_str, s1);
	new_str[s1_len] = glue;
	return (ft_strcat(new_str, s2));
}
