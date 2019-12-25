/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:12:29 by mel-idri          #+#    #+#             */
/*   Updated: 2019/04/12 15:02:27 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lnk_ptr;
	t_list *start;

	if (lst == NULL || f == NULL)
		return (NULL);
	start = (*f)(lst);
	lnk_ptr = start;
	while (lst->next && lnk_ptr)
	{
		lnk_ptr->next = (*f)(lst->next);
		lnk_ptr = lnk_ptr->next;
		lst = lst->next;
	}
	return (start);
}
