/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:13:48 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/20 02:34:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_inodes(t_queue *inodes, int is_dir)
{
	if (F_IS_SET(g_options, OPT_L))
		print_inodes_longlist(inodes, is_dir);
	else
		print_inodes_default(inodes);
}
