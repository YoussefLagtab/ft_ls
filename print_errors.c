/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:58:12 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 19:37:58 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *filename)
{
	char	*msg;

	if ((msg = ft_strjoin("ft_ls: ", filename)) == NULL)
		exit(1);
	perror(msg);
	free(msg);
}

void		print_errors(t_queue *errors)
{
	t_list	*err_node;
	t_list	*tmp;
	t_error *err;

	err_node = errors->head;
	// sort_file_list(err_node, compare_filename);
	while (err_node)
	{
		err = (t_error*)err_node->content;
		errno = err->error_no;
		print_error(err->arg);
		tmp = err_node;
		err_node = err_node->next;
	}
}
