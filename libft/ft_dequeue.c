/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:37:22 by ylagtab           #+#    #+#             */
/*   Updated: 2019/12/24 19:03:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*dequeue(t_queue *queue)
{
	t_list	*node;

	if (queue == NULL || queue->head == NULL)
		return (NULL);
	node = queue->head;
	queue->head = node->next;
	node->next = NULL;
	queue->length--;
	if (queue->length == 0)
		queue->tail = NULL;
	return (node);
}
