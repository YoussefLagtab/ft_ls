/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:07:26 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 19:22:58 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

int		compare_filename(t_list *node1, t_list *node2)
{
	return (ft_strcmp(((t_inode*)node1->content)->name,
		((t_inode*)node2->content)->name));
}
