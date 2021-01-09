/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_user_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:26 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/09 11:36:24 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	fill_group(t_inode_details *i_details, t_ll_specs *ll_specs,
			gid_t st_gid)
{
	struct group	*gr;
	int				gr_len;

	if ((gr = getgrgid(st_gid)) != NULL)
		i_details->gr = ft_strdup(gr->gr_name);
	gr_len = ft_strlen(i_details->gr);
	if (gr_len > ll_specs->gr_len)
		ll_specs->gr_len = gr_len;
}

void	fill_user(t_inode_details *i_details, t_ll_specs *ll_specs,
			uid_t st_uid)
{
	struct passwd	*pw;
	int				user_len;

	if ((pw = getpwuid(st_uid)) != NULL)
		i_details->user = ft_strdup(pw->pw_name);
	user_len = ft_strlen(i_details->user);
	if (user_len > ll_specs->user_len)
		ll_specs->user_len = user_len;
}
