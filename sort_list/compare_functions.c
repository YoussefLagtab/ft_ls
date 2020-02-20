/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:35:16 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 19:27:15 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*min_list(t_list *list1, t_list *list2,
		int (*comparator)(t_list*, t_list*))
{
	return (comparator(list1, list2) < 0 ? list1 : list2);
}
