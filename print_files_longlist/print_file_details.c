/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_details.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:55:05 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 09:55:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	print_file_details(t_file_details *f_details, t_ll_specs *ll_specs)
{
	mode_t	st_mode;
	dev_t	st_rdev;

	st_mode = f_details->st_mode;
	st_rdev = f_details->st_rdev;
	ft_printf("%s ", f_details->perm);
	ft_printf("%*hhd ", ll_specs->hard_links_len, f_details->nlink);
	ft_printf("%-*s  ", ll_specs->user_len, f_details->user);
	ft_printf("%-*s  ", ll_specs->gr_len, f_details->gr);
	if (S_ISBLK(st_mode) || S_ISCHR(st_mode))
		ft_printf("%4d,%4d ", major(st_rdev), minor(st_rdev));
	else
		ft_printf("%*d ", ll_specs->size_len, f_details->size);
	ft_printf("%s ", f_details->time);
	ft_printf("%s\n", f_details->name);
}
