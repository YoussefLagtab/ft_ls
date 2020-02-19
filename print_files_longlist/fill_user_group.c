/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_user_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:26 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 10:00:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_group(t_file_details *f_details, t_ll_specs *ll_specs,
			gid_t st_gid)
{
	struct group	*gr;
	int				gr_len;

	if ((gr = getgrgid(st_gid)) != NULL)
		f_details->gr = gr->gr_name;
	gr_len = ft_strlen(f_details->gr);
	if (gr_len > ll_specs->gr_len)
		ll_specs->gr_len = gr_len;
}

void	fill_user(t_file_details *f_details, t_ll_specs *ll_specs,
			uid_t st_uid)
{
	struct passwd	*pw;
	int				user_len;

	if ((pw = getpwuid(st_uid)) != NULL)
		f_details->user = pw->pw_name;
	user_len = ft_strlen(f_details->user);
	if (user_len > ll_specs->user_len)
		ll_specs->user_len = user_len;
}
