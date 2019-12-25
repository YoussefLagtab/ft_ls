/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:44:28 by mel-idri          #+#    #+#             */
/*   Updated: 2019/10/07 13:22:36 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *s;

	if ((s = (char *)malloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	return (ft_strcpy(s, s1));
}
