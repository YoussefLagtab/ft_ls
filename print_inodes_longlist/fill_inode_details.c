/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_inode_details.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:38:22 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/08 16:04:18 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	fill_inode_details(t_inode_details *i_details, t_ll_specs *ll_specs,
	t_inode *inode)
{
	i_details->st_mode = inode->st.st_mode;
	i_details->st_rdev = inode->st.st_rdev;
	fill_perm(i_details);
	fill_acl_ext(i_details, inode);
	fill_nlink(i_details, ll_specs, inode->st.st_nlink);
	fill_user(i_details, ll_specs, inode->st.st_uid);
	fill_group(i_details, ll_specs, inode->st.st_gid);
	fill_size(i_details, ll_specs, inode->st.st_size);
	if (F_IS_SET(g_options, OPT_U))
		fill_time(i_details, ll_specs, inode->st.st_atimespec.tv_sec);
	else
		fill_time(i_details, ll_specs, inode->st.st_mtimespec.tv_sec);
	fill_name(i_details, ll_specs, inode);
}
