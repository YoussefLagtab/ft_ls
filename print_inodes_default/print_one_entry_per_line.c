/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_entry_per_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:17:38 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/22 11:27:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_default.h"

void	print_one_entry_per_line(t_queue *inodes)
{
	t_inode	*inode;
	t_list	**list_node;

	list_node = &inodes->head;
	while (*list_node)
	{
		inode = (t_inode*) (*list_node)->content;
		ft_printf("%s", inode->name);
		if (g_options[OPT_P] == 1 && S_ISDIR(inode->st.st_mode))
			ft_putchar('/');
		ft_putchar('\n');
		list_node = &(*list_node)->next;
	}
}
