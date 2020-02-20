/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:34:05 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 23:09:00 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_cmp_func g_ft_ls_compare;

static t_list	*min_list(t_list *list1, t_list *list2,
		int (*comparator)(t_list*, t_list*))
{
	return (comparator(list1, list2) < 0 ? list1 : list2);
}

static void		split_list(t_list *first_half, t_list **seconed_half,
				int orig_list_len)
{
	int		first_half_len;
	int		i;
	t_list	*iterator;

	iterator = first_half;
	first_half_len = orig_list_len / 2;
	i = 0;
	while (i < first_half_len - 1)
	{
		iterator = iterator->next;
		i++;
	}
	*seconed_half = iterator->next;
	iterator->next = NULL;
}

static t_list	*merge_sorted_lists(t_list *list1, t_list *list2)
{
	t_list *head;
	t_list **tail;

	tail = &head;
	while (list1 && list2)
	{
		*tail = min_list(list1, list2, g_ft_ls_compare);
		if (*tail == list1)
			list1 = list1->next;
		if (*tail == list2)
			list2 = list2->next;
		tail = &(*tail)->next;
	}
	*tail = list1 ? list1 : list2;
	return (head);
}

static void		merge_sort(t_list **file_list, int list_length)
{
	t_list *list1;
	t_list *list2;

	list1 = *file_list;
	if (list_length <= 1)
		return ;
	split_list(list1, &list2, list_length);
	merge_sort(&list1, list_length / 2);
	merge_sort(&list2, list_length / 2 + list_length % 2);
	*file_list = merge_sorted_lists(list1, list2);
}

t_queue			*sort_list(t_queue *files, t_cmp_func cmp_func)
{
	g_ft_ls_compare = cmp_func;
	merge_sort(&files->head, files->length);
	return (files);
}
