/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:38:22 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 15:50:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_file_details(t_inode *inode, t_file_details *f_details,
	t_ll_specs *ll_specs)
{
	f_details->st_mode = inode->st.st_mode;
	f_details->st_rdev = inode->st.st_rdev;
	fill_perm(f_details);
	fill_acl_ext(inode, f_details);
	fill_nlink(f_details, ll_specs, inode->st.st_nlink);
	fill_user(f_details, ll_specs, inode->st.st_uid);
	fill_group(f_details, ll_specs, inode->st.st_gid);
	fill_size(f_details, ll_specs, inode->st.st_size);
	fill_time(f_details, ll_specs, inode->st.st_mtimespec.tv_sec);
	fill_name(f_details, ll_specs, inode);
}
