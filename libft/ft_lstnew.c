/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:18:09 by mel-idri          #+#    #+#             */
/*   Updated: 2020/03/09 15:34:28 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lnk_ptr;

	if ((lnk_ptr = (t_list *)safe_malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		if ((lnk_ptr->content = safe_malloc(content_size)) == NULL)
		{
			free(lnk_ptr);
			return (NULL);
		}
		ft_memcpy(lnk_ptr->content, content, content_size);
		lnk_ptr->content_size = content_size;
	}
	else
	{
		lnk_ptr->content = NULL;
		lnk_ptr->content_size = 0;
	}
	lnk_ptr->next = NULL;
	return (lnk_ptr);
}
