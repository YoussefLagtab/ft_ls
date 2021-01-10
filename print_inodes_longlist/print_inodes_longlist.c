/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes_longlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:32:43 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/10 10:28:25 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

static void	free_i_details_content(t_inode_details *i_details)
{
	ft_strdel(&i_details->name);
	ft_strdel(&i_details->user);
	ft_strdel(&i_details->gr);
	ft_strdel(&i_details->time);
	ft_memdel((void**)&i_details);
}

static void	fill_all_inode_details(t_queue *inodes, t_queue *inodes_details,
	t_ll_specs *ll_specs)
{
	t_list			**list_node;
	t_inode			*inode;
	t_inode_details	i_details;

	list_node = &inodes->head;
	while (*list_node)
	{
		inode = (t_inode*)(*list_node)->content;
		fill_inode_details(&i_details, ll_specs, inode);
		ll_specs->total += (size_t)inode->st.st_blocks;
		ft_enqueue(inodes_details, &i_details, sizeof(t_inode_details));
		list_node = &(*list_node)->next;
	}
}

void		print_inodes_longlist(t_queue *inodes, int is_dir)
{
	t_ll_specs		ll_specs;
	t_queue			inodes_details;
	t_inode_details	*i_details;
	t_list			*lst_node;

	ft_bzero(&ll_specs, sizeof(t_ll_specs));
	ft_bzero(&inodes_details, sizeof(t_queue));
	fill_all_inode_details(inodes, &inodes_details, &ll_specs);
	if (is_dir)
		ft_printf("total %d\n", ll_specs.total);
	while (inodes_details.length)
	{
		lst_node = ft_dequeue(&inodes_details);
		i_details = (t_inode_details*)lst_node->content;
		print_inode_details(i_details, &ll_specs);
		free_i_details_content(i_details);
		ft_memdel((void**)&lst_node);
	}
}
