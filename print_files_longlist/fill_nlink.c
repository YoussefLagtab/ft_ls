/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 09:53:54 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_nlink(t_file_details *f_details, t_ll_specs *ll_specs,
	nlink_t st_nlink)
{
	int hl_len;

	hl_len = ft_nbrlen(st_nlink);
	f_details->nlink = st_nlink;
	if (hl_len > ll_specs->hard_links_len)
		ll_specs->hard_links_len = hl_len;
}
