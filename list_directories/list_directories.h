/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_directories.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:24:50 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 02:47:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DIRECTORIES_H
# define LIST_DIRECTORIES_H

# include "../ft_ls.h"

void	list_dir(t_inode *dir);
void	list_subdirs(t_queue *inodes);
void	get_dir_content(t_queue *dir_content, char *dir_path, t_inode *dir);

#endif