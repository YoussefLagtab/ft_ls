/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_entry_per_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:17:38 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 04:21:54 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_default.h"

void	print_one_entry_per_line(t_queue *inodes)
{
	t_inode	*inode;
	// t_list	*iter;

	// iter = inodes->head;
	while (inodes->length)
	{
		inode = (t_inode*)ft_dequeue(inodes);
		ft_printf("%s\n", inode->name);
		// iter = iter->next;
		// free(inode);
	}
}
