/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inode_details.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:55:05 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 04:12:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	print_inode_details(t_inode_details *inode_details,
	t_ll_specs *ll_specs)
{
	mode_t	st_mode;
	dev_t	st_rdev;

	st_mode = inode_details->st_mode;
	st_rdev = inode_details->st_rdev;
	ft_printf("%s ", inode_details->perm);
	ft_printf("%*hhd ", ll_specs->hard_links_len, inode_details->nlink);
	ft_printf("%-*s  ", ll_specs->user_len, inode_details->user);
	// ft_printf("%-*s  ", ll_specs->gr_len, inode_details->gr);
	// ft_printf("%-*s  ", ll_specs->gr_len, inode_details->gr);
	if (S_ISBLK(st_mode) || S_ISCHR(st_mode))
		ft_printf("%4d,%4d ", major(st_rdev), minor(st_rdev));
	else
		ft_printf("%*d ", ll_specs->size_len, inode_details->size);
	ft_printf("%s ", inode_details->time);
	ft_printf("%s\n", inode_details->name);
}
