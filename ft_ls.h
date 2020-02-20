/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:55:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 02:34:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <time.h>
# include "libft/libft.h"
# include <stdio.h>
# include "includes/typedefs_macros.h"
# include "get_cmp_func/get_cmp_func.h"

t_inode		*new_inode(t_inode *inode, struct stat *st, char *path, char *name);
t_error		*new_error(t_error *error, char *path);
void		ft_parse(t_args *ls_args, char **av);
void		handle_link(t_inode *inode, t_args *ls_args);
void		print_error(char *filename);
void		print_errors(t_queue *errors);
void		print_inodes(t_queue *inodes, int is_dir);
void		print_inodes_default(t_queue *inodes);
void		print_inodes_longlist(t_queue *inodes, int is_dir);
void		list_directories(t_queue *dirs);
t_queue		*sort_list(t_queue *files, t_cmp_func cmp_func);

#endif
