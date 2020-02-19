/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:19 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 10:04:16 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_size(t_file_details *f_details, t_ll_specs *ll_specs,
	off_t st_size)
{
	int		size_len;
	mode_t	st_mode;

	st_mode = f_details->st_mode;
	if (S_ISBLK(st_mode) || S_ISCHR(st_mode))
		size_len = 9;
	else
		size_len = ft_nbrlen(st_size);
	f_details->size = st_size;
	if (size_len > ll_specs->size_len)
		ll_specs->size_len = size_len;
}
