/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:37:23 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 15:00:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_symlink_to_dir(char *filename)
{
	struct stat st;

	return (stat(filename, &st) == 0 && S_ISDIR(st.st_mode));
}

void		handle_link(t_inode *inode, t_args *ls_args)
{
	int end_with_slash;

	end_with_slash = inode->name[ft_strlen(inode->name) - 1] == '/';
	if (is_symlink_to_dir(inode->name))
	{
		if (!F_IS_SET(g_options, OPT_L) || end_with_slash)
			ft_enqueue(&(ls_args->dirs), &inode, sizeof(t_inode));
		return ;
	}
	ft_enqueue(&(ls_args->files), &inode, sizeof(t_inode));
}
