/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes_longlist.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:39:11 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/12 10:05:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INODES_LONGLIST_H
# define PRINT_INODES_LONGLIST_H

# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include "../ft_ls.h"

typedef struct	s_inode_details
{
	char	*name;
	char	*user;
	char	*gr;
	char	*time;
	size_t	size;
	dev_t	st_rdev;
	mode_t	st_mode;
	nlink_t	nlink;
	char	perm[11];
	char	acl_ext;
}				t_inode_details;

typedef struct	s_ll_specs
{
	size_t	total;
	short	hard_links_len;
	short	user_len;
	short	gr_len;
	short	size_len;
	short	time_len;
	short	name_len;
}				t_ll_specs;

void			fill_perm(t_inode_details *i_details);
void			fill_acl_ext(t_inode_details *i_details, t_inode *inode);
void			fill_nlink(t_inode_details *i_details, t_ll_specs *ll_specs,
					nlink_t st_nlink);
void			fill_user(t_inode_details *i_details, t_ll_specs *ll_specs,
					uid_t st_uid);
void			fill_group(t_inode_details *i_details, t_ll_specs *ll_specs,
					gid_t st_gid);
void			fill_size(t_inode_details *i_details, t_ll_specs *ll_specs,
					off_t st_size);
void			fill_time(t_inode_details *i_details, t_ll_specs *ll_specs,
					time_t st_time);
void			fill_name(t_inode_details *i_details, t_ll_specs *ll_specs,
					t_inode *inode);
void			fill_inode_details(t_inode_details *i_details,
					t_ll_specs *ll_specs, t_inode *inode);
void			print_inode_details(t_inode_details *i_details,
					t_ll_specs *ll_specs);
void			print_inodes_longlist(t_queue *inodes, int is_dir);

#endif
