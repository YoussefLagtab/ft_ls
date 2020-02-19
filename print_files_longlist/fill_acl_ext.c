/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_acl_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:44:23 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 10:09:42 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_acl_ext(t_inode *inode, t_file_details *f_details)
{
	ssize_t	xattr;
	acl_t	acl;
	char	*full_path;

	full_path = ft_strglue(inode->path, '/', inode->name);
	acl = acl_get_file(full_path, ACL_TYPE_EXTENDED);
	xattr = listxattr(full_path, NULL, 0, XATTR_NOFOLLOW);
	f_details->acl_ext = ' ';
	if (xattr > 0)
		f_details->acl_ext = '@';
	else if (acl != NULL)
		f_details->acl_ext = '+';
	acl_free(acl);
	free(full_path);
}
