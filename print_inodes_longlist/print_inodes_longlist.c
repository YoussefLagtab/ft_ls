/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes_longlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:32:43 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/09 21:23:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	print_inodes_longlist(t_queue *inodes, int is_dir)
{
	t_inode_details	i_details;
	t_ll_specs		ll_specs;
	t_inode			*inode;
	t_queue			inodes_details;
	t_list			**list_node;

	ft_bzero(&ll_specs, sizeof(t_ll_specs));
	ft_bzero(&inodes_details, sizeof(t_queue));
	list_node = &inodes->head;
	while (*list_node)
	{
		inode = (t_inode*) (*list_node)->content;
		ft_bzero(&i_details, sizeof(t_inode_details));
		fill_inode_details(&i_details, &ll_specs, inode);
		ll_specs.total += (size_t)inode->st.st_blocks;
		ft_enqueue(&inodes_details, &i_details, sizeof(t_inode_details));
		list_node = &(*list_node)->next;
	}
	if (is_dir)
		ft_printf("total %d\n", ll_specs.total);
	while (inodes_details.length)
	{
		i_details = *((t_inode_details*)ft_dequeue(&inodes_details)->content);
		print_inode_details(&i_details, &ll_specs);
	}
}
