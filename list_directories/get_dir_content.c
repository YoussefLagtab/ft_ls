/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:12:28 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/20 00:26:28 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_directories.h"

static void	add_inode_to_dir_content(t_queue *dir_content, char *dir_path,
	char *inode_name)
{
	struct stat st;
	char		*full_inode_path;
	t_inode		inode;

	full_inode_path = ft_strglue(dir_path, '/', inode_name);
	if (lstat(full_inode_path, &st) == -1)
	{
		print_error(full_inode_path);
		free(full_inode_path);
		return ;
	}
	new_inode(&inode, &st, dir_path, inode_name);
	ft_enqueue(dir_content, &inode, sizeof(t_inode));
	free(full_inode_path);
}

void	get_dir_content(t_queue *dir_content, char *dir_path, t_inode *dir)
{
	struct dirent	*dir_entry;
	DIR				*current_dir;

	ft_bzero(dir_content, sizeof(t_queue));
	if ((current_dir = opendir(dir_path)) == NULL)
		return (print_error(dir->name));
	while ((dir_entry = readdir(current_dir)) != NULL)
	{
		if (dir_entry->d_name[0] == '.' && !F_IS_SET(g_options, OPT_A))
			continue ;
		add_inode_to_dir_content(dir_content, dir_path, dir_entry->d_name);
	}
	closedir(current_dir);
}
