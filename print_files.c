/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:13:48 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 19:38:18 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_files(t_list *files)
{
	if (F_IS_SET(g_options, OPT_L))
		print_files_longlist(files, 0);
	// ft_printf("g_options %d\n", g_options['l']);
	// else
		// print_files_default(files);
}
