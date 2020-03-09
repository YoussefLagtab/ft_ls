/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:36:34 by mel-idri          #+#    #+#             */
/*   Updated: 2020/03/09 17:47:47 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_queue(t_queue *queue)
{
	t_list	*current;
	t_list	*tmp_next;

	if (queue == NULL || (tmp_next = queue->head) == NULL)
		return ;
	current = tmp_next;
	while (tmp_next)
	{
		tmp_next = current->next;
		free(current->content);
		free(current);
		current = tmp_next;
	}
}