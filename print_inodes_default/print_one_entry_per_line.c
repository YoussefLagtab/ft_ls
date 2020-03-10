/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_entry_per_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:17:38 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/09 21:23:09 by mel-idri         ###   ########.fr       */
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
		if (F_IS_SET(g_options, OPT_P) && S_ISDIR(inode->st.st_mode))
			ft_putchar('/');
		ft_putchar('\n');
		list_node = &(*list_node)->next;
	}
}
