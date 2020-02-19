/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_longlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:32:43 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 15:53:46 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	print_files_longlist(t_list *files_list, int is_dir)
{
	t_file_details	f_details;
	t_ll_specs		ll_specs;
	t_inode			*inode;
	t_queue			files_details;

	ft_bzero(&ll_specs, sizeof(t_ll_specs));
	ft_bzero(&files_details, sizeof(t_queue));
	while (files_list)
	{
		inode = (t_inode*)files_list->content;
		ft_bzero(&f_details, sizeof(t_file_details));
		fill_file_details(inode, &f_details, &ll_specs);
		ll_specs.total += (size_t)inode->st.st_blocks;
		ft_enqueue(&files_details, &f_details, sizeof(t_file_details));
		files_list = files_list->next;
	}
	if (is_dir)
		ft_printf("total %d\n", ll_specs.total);
	while (files_details.length)
	{
		f_details = *((t_file_details*)ft_dequeue(&files_details)->content);
		print_file_details(&f_details, &ll_specs);
	}
}
