/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:24:35 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/22 11:27:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_directories.h"

static char	*get_full_dir_path(t_inode *dir)
{
	char	*full_dir_path;

	if (ft_strequ(dir->path, ""))
		full_dir_path = ft_strdup(dir->name);
	else
		full_dir_path = ft_strglue(dir->path, '/', dir->name);
	return (full_dir_path);
}

static void	print_dir_path(char *dir_path)
{
	static int	is_not_first_dir;
	static int	is_multi_dir_mode;

	if (!is_multi_dir_mode)
		is_multi_dir_mode = g_is_multi_dir_mode;
	if (is_not_first_dir)
		ft_putstr("\n");
	else
		is_not_first_dir = 1;
	if (is_multi_dir_mode)
		ft_printf("%s:\n", dir_path);
	else
		is_multi_dir_mode = 1;
}

void		list_dir(t_inode *dir)
{
	static t_cmp_func	cmp_func;
	t_queue				content;
	char				*full_dir_path;

	full_dir_path = get_full_dir_path(dir);
	if (!cmp_func)
		cmp_func = get_cmp_func();
	print_dir_path(full_dir_path);
	get_dir_content(&content, full_dir_path, dir);
	if (content.length)
	{
		sort_list(&content, cmp_func);
		print_inodes(&content, 1);
		if (g_options[OPT_CAP_R] == 1)
			list_subdirs(&content);
	}
	free(full_dir_path);
}
