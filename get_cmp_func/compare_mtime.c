/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_mtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:10:22 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/08 15:50:37 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

int		compare_mtime(t_list *node1, t_list *node2)
{
	t_inode	*inode1;
	t_inode	*inode2;
	time_t	inode1_mtime;
	time_t	inode2_mtime;

	inode1 = (t_inode*)node1->content;
	inode2 = (t_inode*)node2->content;
	inode1_mtime = inode1->st.st_mtimespec.tv_sec;
	inode2_mtime = inode2->st.st_mtimespec.tv_sec;
	if (inode1_mtime > inode2_mtime)
		return (-1);
	if (inode1_mtime < inode2_mtime)
		return (1);
	return (ft_strcmp(inode1->name, inode2->name));
}
