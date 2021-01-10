/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:39:33 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 18:15:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

int		compare_size(t_list *node1, t_list *node2)
{
	const t_inode	*inode1 = (t_inode*)node1->content;
	const t_inode	*inode2 = (t_inode*)node2->content;
	const off_t		inode1_size = inode1->st.st_size;
	const off_t		inode2_size = inode2->st.st_size;

	if (inode1_size > inode2_size)
		return (-1);
	if (inode1_size < inode2_size)
		return (1);
	return (ft_strcmp(inode1->name, inode2->name));
}
