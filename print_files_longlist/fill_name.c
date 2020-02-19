/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:04 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 15:25:40 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_name(t_file_details *f_details, t_ll_specs *ll_specs,
	t_inode *inode)
{
	int		name_len;
	ssize_t	buf_size;
	char	buf[PATH_MAX + 1];
	char	*link_path;

	f_details->name = ft_strdup((char *)inode->name);
	if (S_ISLNK(inode->st.st_mode))
	{
		link_path = ft_strglue(inode->path, '/', inode->name);
		if (link_path && (buf_size = readlink(link_path, buf, PATH_MAX)) != -1)
		{
			buf[buf_size] = '\0';
			f_details->name = ft_strjoin_free(f_details->name, " -> ", 1, 0);
			f_details->name = ft_strjoin_free(f_details->name, buf, 1, 0);
		}
		ft_strdel(&link_path);
	}
	name_len = ft_strlen(f_details->name);
	if (name_len > ll_specs->name_len)
		ll_specs->name_len = name_len;
}
