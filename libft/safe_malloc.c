/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:38:16 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 18:02:31 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*safe_malloc(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)) == NULL)
		exit(1);
	else
		return (ptr);
}
