/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:13:01 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/20 02:39:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_directories.h"

void		list_directories(t_queue *dirs)
{
	t_list *directory;

	directory = dirs->head;
	while (directory)
	{
		list_dir(((t_inode*)directory->content));
		directory = directory->next;
	}
}
