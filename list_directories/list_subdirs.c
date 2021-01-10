/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_subdirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:51:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 18:16:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_directories.h"

void	list_subdirs(t_queue *inodes)
{
	t_inode *inode;
	int		is_current_dir;
	int		is_parent_dir;
	int		is_dir;
	t_list	**list_node;

	list_node = &inodes->head;
	while (*list_node)
	{
		inode = (t_inode*)(*list_node)->content;
		is_dir = S_ISDIR(inode->st.st_mode);
		is_current_dir = ft_strequ(inode->name, ".");
		is_parent_dir = ft_strequ(inode->name, "..");
		if (is_dir && !is_current_dir && !is_parent_dir)
			list_dir(inode);
		list_node = &(*list_node)->next;
	}
}
