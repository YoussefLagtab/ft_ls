/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_atime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:15:41 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 19:22:45 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

int		compare_atime(t_list *node1, t_list *node2)
{
	t_inode	*inode1;
	t_inode	*inode2;
	time_t	inode1_atime;
	time_t	inode2_atime;

	inode1 = (t_inode*)node1->content;
	inode2 = (t_inode*)node2->content;
	inode1_atime = inode1->st.st_atimespec.tv_sec;
	inode2_atime = inode2->st.st_atimespec.tv_sec;
	if (inode1_atime < inode2_atime)
		return (-1);
	if (inode1_atime > inode2_atime)
		return (1);
	return (ft_strcmp(inode1->name, inode2->name));
}
