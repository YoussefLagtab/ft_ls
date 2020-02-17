/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:55:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 17:09:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft/libft.h"
# include "includes/typedefs_macros.h"

void	ft_parse(t_args *ls_args, char **av);
t_inode	*new_inode(t_inode *inode, struct stat *st, char *path, char *name);
t_error	*new_error(t_error *error, char *path);
void	handle_link(t_inode *inode, t_args *ls_args);

#endif
