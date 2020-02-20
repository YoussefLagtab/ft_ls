/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 01:02:19 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_longlist.h"

void	fill_nlink(t_inode_details *i_details, t_ll_specs *ll_specs,
	nlink_t st_nlink)
{
	int hl_len;

	hl_len = ft_nbrlen(st_nlink);
	i_details->nlink = st_nlink;
	if (hl_len > ll_specs->hard_links_len)
		ll_specs->hard_links_len = hl_len;
}
