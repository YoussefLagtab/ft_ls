/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_acl_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:44:23 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/13 04:34:01 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	fill_acl_ext(t_inode_details *i_details, t_inode *inode)
{
	ssize_t	xattr;
	acl_t	acl;
	char	*full_path;

	full_path = ft_strglue(inode->path, '/', inode->name);
	acl = acl_get_link_np(full_path, ACL_TYPE_EXTENDED);
	xattr = listxattr(full_path, NULL, 0, XATTR_NOFOLLOW);
	i_details->acl_ext = ' ';
	if (xattr > 0)
		i_details->acl_ext = '@';
	else if (acl != NULL)
		i_details->acl_ext = '+';
	acl_free(acl);
	free(full_path);
}
