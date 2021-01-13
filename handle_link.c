/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:37:23 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/12 12:34:43 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		handle_link(t_inode *inode, t_args *ls_args)
{
	int				end_with_slash;
	int				is_symlink_to_dir;
	struct stat		st;

	end_with_slash = inode->name[ft_strlen(inode->name) - 1] == '/';
	is_symlink_to_dir = stat(inode->name, &st) == 0 && S_ISDIR(st.st_mode);
	if (is_symlink_to_dir)
	{
		if (g_options[OPT_L] != 1 || end_with_slash)
		{
			ft_enqueue(&(ls_args->dirs), inode, sizeof(t_inode));
			return ;
		}
	}
	ft_enqueue(&(ls_args->files), inode, sizeof(t_inode));
}
