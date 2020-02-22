/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:04 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/22 21:58:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	fill_name(t_inode_details *i_details, t_ll_specs *ll_specs,
	t_inode *inode)
{
	int		name_len;
	ssize_t	buf_size;
	char	buf[PATH_MAX + 1];
	char	*link_path;

	i_details->name = ft_strdup((char *)inode->name);
	if (S_ISLNK(inode->st.st_mode))
	{
		link_path = ft_strglue(inode->path, '/', inode->name);
		if (link_path && (buf_size = readlink(link_path, buf, PATH_MAX)) != -1)
		{
			buf[buf_size] = '\0';
			i_details->name = ft_strjoin_free(i_details->name, " -> ", 1, 0);
			i_details->name = ft_strjoin_free(i_details->name, buf, 1, 0);
		}
		ft_strdel(&link_path);
	}
	else if (F_IS_SET(g_options, OPT_P) && S_ISDIR(inode->st.st_mode))
		i_details->name = ft_strjoin_free(i_details->name, "/", 1, 0);
	name_len = ft_strlen(i_details->name);
	if (name_len > ll_specs->name_len)
		ll_specs->name_len = name_len;
}
