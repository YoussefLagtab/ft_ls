/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_subdirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:51:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/20 02:48:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_directories.h"

void	list_subdirs(t_queue *inodes)
{
	t_inode *inode;
	int		is_current_dir;
	int		is_parrent_dir;
	int		is_dir;

	while (inodes->length)
	{
		inode = (t_inode*)ft_dequeue(inodes);
		is_dir = S_ISDIR(inode->st.st_mode);
		is_current_dir = ft_strequ(inode->name, ".");
		is_parrent_dir = ft_strequ(inode->name, "..");
		if (is_dir && !is_current_dir && !is_parrent_dir)
			list_dir(inode);
	}
}
