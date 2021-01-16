/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:55:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/16 17:05:04 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

int		compare_error(t_list *node1, t_list *node2)
{
	return (ft_strcmp(((t_error*)node1->content)->arg,
		((t_error*)node2->content)->arg));
}
