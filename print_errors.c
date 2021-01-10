/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:58:12 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 18:14:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *filename)
{
	char	*msg;

	msg = ft_strjoin("ft_ls: ", filename);
	perror(msg);
	free(msg);
}

void	print_errors(t_queue *errors)
{
	t_list	*err_node;
	t_error *err;

	while ((err_node = ft_dequeue(errors)))
	{
		err = (t_error*)err_node->content;
		errno = err->error_no;
		print_error(err->arg);
		free(err_node->content);
		free(err_node);
	}
}
